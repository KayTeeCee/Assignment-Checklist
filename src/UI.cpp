#include "UI.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using std::string;
using std::vector;
using std::cin;
using std::cout;

string getNonEmptyLine(const string& prompt) {
    string line;
    while (true) {
        cout << prompt;
        std::getline(cin, line);
        if (!line.empty()) {
            return line;
        }
        cout << "Input can't be empty.\n";
    }
}

double getNumberInRange(const string& prompt, double low, double high) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val && val >= low && val <= high) {
            cin.ignore(1000, '\n');
            return val;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Enter a number from " << low << " to " << high << ".\n";
    }
}

void UI::run() {
    int choice = -1;
    while (choice != 0) {
        showMenu();
        choice = (int)getNumberInRange("Choose an option: ", 0, 9);
        cout << "\n";

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
    cout << "1. Add a course\n";
    cout << "2. Delete a course\n";
    cout << "3. View courses\n";
    cout << "4. Add a grade category\n";
    cout << "5. Change a letter grade cutoff\n";
    cout << "6. Add an assignment\n";
    cout << "7. Edit an assignment\n";
    cout << "8. View priority list\n";
    cout << "9. Mark an assignment as done\n";
    cout << "0. Quit\n";
}

void UI::addCourse() {
    string name = getNonEmptyLine("Course name: ");
    const vector<Course>& courses = queue.getCourses();
    for (const auto& course : courses) {
        if (course.courseName == name) {
            cout << "You already have a course called " << name << ".\n";
            return;
        }
    }
    queue.addCourse((name));
    cout << "  Added " << name << ".\n";
}

void UI::deleteCourse() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    string name = c->courseName;
    queue.removeCourse(name);
    cout << " Deleted " << name << ".\n";
    }

void UI::showCourses() const {
    const vector<Course>& courses = queue.getCourses();
    if (courses.empty()) {
        cout << "No courses yet.\n";
        return;
    }

    bool first = true;
    for (const auto& c : courses) {
        if (!first) cout << "\n";
        first = false;

        cout << c.courseName << "\n";
        for (int i = 0; i < 4; i++) {
            cout << "  " << char('A' + i) << " starts at " << c.letterRange[i] * 100 << "%\n";
        }

        if (c.categories.empty()) {
            cout << "  No categories added yet.\n";
        }
        else {
            for (const auto& cat : c.categories) {
                cout << "  " << cat.first << ": " << cat.second * 100 << "%\n";
            }
        }
    }
}

Course* UI::chooseCourse() {
    vector<Course>& courses = queue.getCourses();
    if (courses.empty()) {
        cout << "No courses added yet.\n";
        return nullptr;
    }
    cout << "Courses:\n";
    for (size_t i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << courses[i].courseName << "\n";
    }
    cout << "\n";
    int pick = (int)getNumberInRange("Pick a course: ", 1, courses.size());
    return &courses[pick - 1];
}

void UI::addCategory() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    string name = getNonEmptyLine("Category name: ");

    if (c->categories.count(name) > 0) {
        cout << "  This category already exists in " << c->courseName << ".\n";
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
        cout << "  Weights now add up to 100%.\n";
    }
    else if (total > 1.0) {
        cout << "  Category weights exceed 100%.\n";
    }
    else {
        cout << "  Saved. Weights don't add up to 100% yet.\n";
    }
}

// Edits letter grade percentages
void UI::editLetterCutoff() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    string input = getNonEmptyLine("Letter (A-D): ");

    if (input.length() != 1) {
        cout << "  Enter only one letter: A, B, C, or D.\n";
        return;
    }

    char letter = std::toupper(input[0]);

    if (letter < 'A' || letter > 'D') {
        cout << "  Letter must be A, B, C or D.\n";
        return; 
    }
    double percent = getNumberInRange("New minimum percent: ", 0, 100);

    // Makes sure grade cutoffs stay in descending order.
    if (c->setLowerBound(letter, percent / 100.0)) {
       cout << "  Updated.\n";
    }
    else {
        cout << "  Not updated, it has to stay between the letters above and below it.\n";
    }
}

void UI::addAssignment() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    if (c->categories.empty()) {
        cout << "  This course has no categories yet. Use option 4 first.\n";
        return;
    }

    vector<string> names;
    for (const auto& cat : c->categories) {
        names.push_back(cat.first);
    }
    cout << "Categories:\n";
    for (size_t i = 0; i < names.size(); i++) {
        cout << i + 1 << ". " << names[i] << "\n";
    }
    cout << "\n";
    int pick = (int)getNumberInRange("Pick a category: ", 1, names.size());
    
    string name = getNonEmptyLine("Assignment name: ");
    queue.addAssignment(c->courseName, names[pick - 1], name);
    cout << " Added " << name << ".\n";
}

void UI::editAssignment() { //Waiting on edit function 
    vector<Assignment> list = queue.sortedAssignments();
    if (list.empty()) {
        cout << "No assignments to edit.\n";
        return;
    }

    cout << "Assignments:\n";
    for (size_t i = 0; i < list.size(); i++) {
        cout << i + 1 << ". " << list[i].assignmentName << " (" << list[i].courseName << ", " << list[i].category << ")\n";
    }
    cout << "\n";

    int pick = (int)getNumberInRange("Pick an assignment: ", 1, list.size());
    Assignment updated = list[pick - 1];

    cout << "1. Edit name\n";
    int field = (int)getNumberInRange("What do you want to change? ", 1, 2);

    if (field == 1) {
        updated.assignmentName = getNonEmptyLine("New assignment name: ");
    }
    else {
        updated.estimatedWorth = (int)getNumberInRange("New estimated worth (points): ", 0, 100000);
    }

    if (queue.updateAssignment(list[pick - 1], updated)) {
        cout << "  Updated " << updated.assignmentName << ".\n";
    }
    else {
        cout << "  Could not update the assignment.\n";
    }
}

void UI::showPriorityList() const {
    vector<Assignment> list = queue.sortedAssignments();
    if (list.empty()) {
        cout << "Nothing to do.\n";
        return;
    }
    cout << "Priority list:\n";
    int index = 1;
    for (const auto& item : list) {
        cout << index++ << ". " << item.assignmentName << " (" << item.courseName << ", " << item.category << ")\n";
        cout << "   Priority: " << item.priority << "\n";
    }
}

void UI::completeNext() {
    vector<Assignment> list = queue.sortedAssignments();
    if (list.empty()) {
        cout << "Nothing to mark done.\n";
        return;
    }
    for (size_t i = 0; i < list.size(); i++) {
        cout << i + 1 << ". " << list[i].assignmentName << " (" << list[i].courseName << ")\n";
    }
    cout << "\n";
    int pick = (int)getNumberInRange("Which one is done? ", 1, list.size());
    Assignment chosen = list[pick - 1]; 
    queue.markDone(chosen.courseName, chosen.assignmentName);
    cout << "  Done: " << chosen.assignmentName << " (" << chosen.courseName << ")\n";
}
