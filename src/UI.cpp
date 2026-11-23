#include "UI.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

std::string getNonEmptyLine(const std::string& prompt) {
    std::string line;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);
        if (!line.empty()) {
            return line;
        }
        std::cout << "Input can't be empty.\n";
    }
}

double getNumberInRange(const std::string& prompt, double low, double high) {
    double val;
    while (true) {
        std::cout << prompt;
        if (std::cin >> val && val >= low && val <= high) {
            std::cin.ignore(1000, '\n');
            return val;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Enter a number from " << low << " to " << high << ".\n";
    }
}

void UI::run() {
    int choice = -1;
    while (choice != 0) {
        showMenu();
        choice = (int)getNumberInRange("Choose an option: ", 0, 9);
        std::cout << "\n";

        switch (choice) {
        case 1: addCourse(); break;
        case 2: deleteCourse(); break;
        case 3: showCourses(); break;
        case 4: addCategory(); break;
        case 5: editLetterCutoff(); break;
        case 6: addAssignment(); break;
        case 7: editAssignment(); break;
        case 8: showPriorityList(); break;
        case 9: completeNext(); break;
        case 0: break;
        }
        std::cout << "\n";
    }
}

void UI::showMenu() const {
    std::cout << "1. Add a course\n";
    std::cout << "2. Delete a course\n";
    std::cout << "3. View courses\n";
    std::cout << "4. Add a grade category\n";
    std::cout << "5. Change a letter grade cutoff\n";
    std::cout << "6. Add an assignment\n";
    std::cout << "7. Edit an assignment\n";
    std::cout << "8. View priority list\n";
    std::cout << "9. Mark an assignment as done\n";
    std::cout << "0. Quit\n";
}

void UI::addCourse() {
    std::string name = getNonEmptyLine("Course name: ");
    const std::vector<Course>& courses = queue.getCourses();
    for (const auto& course : courses) {
        if (course.courseName == name) {
            std::cout << "You already have a course called " << name << ".\n";
            return;
        }
    }
    queue.addCourse((name));
    std::cout << "  Added " << name << ".\n";
}

void UI::deleteCourse() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    std::string name = c->courseName;
    queue.removeCourse(name);
    std::cout << " Deleted " << name << ".\n";
    }

void UI::showCourses() const {
    const std::vector<Course>& courses = queue.getCourses();
    if (courses.empty()) {
        std::cout << "No courses yet.\n";
        return;
    }

    bool first = true;
    for (const auto& c : courses) {
        if (!first) std::cout << "\n";
        first = false;

        std::cout << c.courseName << "\n";
        for (int i = 0; i < 4; i++) {
            std::cout << "  " << char('A' + i) << " starts at " << c.letterRange[i] * 100 << "%\n";
        }

        if (c.categories.empty()) {
            std::cout << "  No categories added yet.\n";
        }
        else {
            for (const auto& cat : c.categories) {
                std::cout << "  " << cat.first << ": " << cat.second * 100 << "%\n";
            }
        }
    }
}

Course* UI::chooseCourse() {
    std::vector<Course>& courses = queue.getCourses();
    if (courses.empty()) {
        std::cout << "No courses added yet.\n";
        return nullptr;
    }
    std::cout << "Courses:\n";
    for (size_t i = 0; i < courses.size(); i++) {
        std::cout << i + 1 << ". " << courses[i].courseName << "\n";
    }
    std::cout << "\n";
    int pick = (int)getNumberInRange("Pick a course: ", 1, courses.size());
    return &courses[pick - 1];
}

void UI::addCategory() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    std::string name = getNonEmptyLine("Category name: ");

    if (c->categories.count(name) > 0) {
        std::cout << "  This category already exists in " << c->courseName << ".\n";
        return;
    }

    double percent = getNumberInRange("Weight in percent: ", 0, 100);
    c->addCategory(name, percent / 100.0);

    double total = 0.0;

    for (const auto& category : c->categories) {
        total += category.second;
    }

    // Weight validation
    if (c->verifyCategories()) {
        std::cout << "  Weights now add up to 100%.\n";
    }
    else if (total > 1.0) {
        std::cout << "  Category weights exceed 100%.\n";
    }
    else {
        std::cout << "  Saved. Weights don't add up to 100% yet.\n";
    }
}

// Edits letter grade percentages
void UI::editLetterCutoff() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    std::string input = getNonEmptyLine("Letter (A-D): ");

    if (input.length() != 1) {
        std::cout << "  Enter only one letter: A, B, C, or D.\n";
        return;
    }

    char letter = std::toupper(input[0]);

    if (letter < 'A' || letter > 'D') {
        std::cout << "  Letter must be A, B, C or D.\n";
        return; 
    }
    double percent = getNumberInRange("New minimum percent: ", 0, 100);

    // Makes sure grade cutoffs stay in descending order.
    if (c->setLowerBound(letter, percent / 100.0)) {
        std::cout << "  Updated.\n";
    }
    else {
        std::cout << "  Not updated, it has to stay between the letters above and below it.\n";
    }
}

void UI::addAssignment() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    if (c->categories.empty()) {
        std::cout << "  This course has no categories yet. Use option 4 first.\n";
        return;
    }

    std::vector<std::string> names;
    for (const auto& cat : c->categories) {
        names.push_back(cat.first);
    }
    std::cout << "Categories:\n";
    for (size_t i = 0; i < names.size(); i++) {
        std::cout << i + 1 << ". " << names[i] << "\n";
    }
    std::cout << "\n";
    int pick = (int)getNumberInRange("Pick a category: ", 1, names.size());
    
    std::string name = getNonEmptyLine("Assignment name: ");
    queue.addAssignment(c->courseName, names[pick - 1], name);
    std::cout << " Added " << name << ".\n";
}

void UI::editAssignment() { //Waiting on edit function 
    std::vector<Assignment> list = queue.sortedAssignments();
    if (list.empty()) {
        std::cout << "No assignments to edit.\n";
        return;
    }

    std::cout << "Assignments:\n";
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << i + 1 << ". " << list[i].assignmentName << " (" << list[i].courseName << ", " << list[i].category << ")\n";
    }
    std::cout << "\n";

    int pick = (int)getNumberInRange("Pick an assignment: ", 1, list.size());
    Assignment updated = list[pick - 1];

    std::cout << "1. Edit name\n";
    int field = (int)getNumberInRange("What do you want to change? ", 1, 2);

    if (field == 1) {
        updated.assignmentName = getNonEmptyLine("New assignment name: ");
    }
    else {
        updated.estimatedWorth = (int)getNumberInRange("New estimated worth (points): ", 0, 100000);
    }

    if (queue.updateAssignment(list[pick - 1], updated)) {
        std::cout << "  Updated " << updated.assignmentName << ".\n";
    }
    else {
        std::cout << "  Could not update the assignment.\n";
    }
}

void UI::showPriorityList() const {
    std::vector<Assignment> list = queue.sortedAssignments();
    if (list.empty()) {
        std::cout << "Nothing to do.\n";
        return;
    }
    std::cout << "Priority list:\n";
    int index = 1;
    for (const auto& item : list) {
        std::cout << index++ << ". " << item.assignmentName << " (" << item.courseName << ", " << item.category << ")\n";
        std::cout << "   Priority: " << item.priority << "\n";
    }
}

void UI::completeNext() {
    std::vector<Assignment> list = queue.sortedAssignments();
    if (list.empty()) {
        std::cout << "Nothing to mark done.\n";
        return;
    }
    for (size_t i = 0; i < list.size(); i++) {
        std::cout << i + 1 << ". " << list[i].assignmentName << " (" << list[i].courseName << ")\n";
    }
    std::cout << "\n";
    int pick = (int)getNumberInRange("Which one is done? ", 1, list.size());
    Assignment chosen = list[pick - 1]; 
    queue.markDone(chosen.courseName, chosen.assignmentName);
    std::cout << "  Done: " << chosen.assignmentName << " (" << chosen.courseName << ")\n";
}
