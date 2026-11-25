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
    doMenu();
}

// Show Main Menu
void UI::showMenu() const {
    cout << "-------------------------------\n";
    cout << "1. Course Options\n";
    cout << "2. Assignment Options\n";
    cout << "3. View Priority List\n";
    cout << "4. Manually Save\n";
    cout << "0. Quit\n";
    cout << "-------------------------------\n";
}

// Do Main Menu
void UI::doMenu() {
    do {
        showMenu();
        int choice = (int)getNumberInRange("Choose an option: ", 0, 4);
        cout << "\n";

        switch (choice) {
        case 1: doCourseOptions(); break;
        case 2: doAssignmentOptions(); break;
        case 3: viewPriorityList(); break;
        case 4: saveManually(); break;
        case 0: break;
        }

        std::cout << "\n";
    } while (1);
}

// Course Options
void UI::showCourseOptions() const {
    cout << "-------------------------------\n";
    cout << "1. Add a course\n";
    cout << "2. Delete a course\n";
    cout << "3. Edit a course\n";
    cout << "4. View courses\n";
    cout << "5. Back to Main Menu\n";
    cout << "-------------------------------\n";
}

// Do Course Options
void UI::doCourseOptions() {
    do {
        showCourseOptions();
        int choice = (int)getNumberInRange("Choose an option: ", 1, 5);
        cout << "\n";

        switch (choice) {
        case 1: addCourse(); break;
        case 2: deleteCourse(); break;
        case 3: editCourse(); break;
        case 4: viewCourses(); break;
        case 5: doMenu(); break;
        }

        std::cout << "\n";
    } while (1);
}

// Assignment Options
void UI::showAssignmentOptions() const {
    cout << "-------------------------------\n";
    cout << "1. Add an assignment\n";
    cout << "2. Delete an assignment\n";
    cout << "3. Edit an assignment\n";
    cout << "4. View assignments\n";
    cout << "5. Mark assignment as done\n";
    cout << "6. Back to Main Menu\n";
    cout << "-------------------------------\n";
}

// Do Assignment Options
void UI::doAssignmentOptions() {
    do {
        showAssignmentOptions();
        int choice = (int)getNumberInRange("Choose an option: ", 1, 6);
        cout << "\n";

        switch (choice) {
        case 1: addAssignment(); break;
        case 2: deleteAssignment(); break;
        case 3: editAssignment(); break;
        case 4: viewAssignments(); break;
        case 5: markAssignmentDone(); break;
        case 6: doMenu(); break;
        }

        std::cout << "\n";
    } while (1);
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

void UI::editCourse() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    doCourseEditOptions(c);

    // TO DO
}

void UI::showCourseEditOptions() const {
    cout << "-------------------------------\n";
    cout << "1. Change this course name\n";
    cout << "2. Change the current grade for this course\n";
    cout << "3. Course Category Options\n";
    cout << "4. Edit Grade Ranges\n";
    cout << "5. Back\n";
    cout << "-------------------------------\n";
}

void UI::doCourseEditOptions(Course* c) {
    do {
        showCourseEditOptions();
        int choice = (int)getNumberInRange("Choose an option: ", 1, 5);
        cout << "\n";

        switch (choice) {
        case 1: editCourseName(c); break;
        case 2: editCourseGrade(c); break;
        case 3: editGradeRange(c); break;
        case 4: categoryOptions(c); break;
        case 5: doCourseOptions(); break; // Go back up one menu
        }

        std::cout << "\n";
    } while (1);
}

void UI::editCourseName(Course* c) {
    string new_name = getNonEmptyLine("New course name: ");
    c->courseName = new_name;
}

void UI::editCourseGrade(Course* c) {
    double new_grade = stod(getNonEmptyLine("New course grade in percent (XX.XX): "));
    c->currentGrade = new_grade;
}

void UI::editGradeRange(Course* c) {
    char new_grade = getNonEmptyLine("Grade you want to change bound for: ").at(0);
    double new_percent_value = stod(getNonEmptyLine("New Percent Value for chosen grade (XX.XX): "));
    c->setLowerBound(new_grade, new_percent_value);
}

void UI::categoryOptions(Course* c) {
    // TO DO
}

void UI::viewCourses() const {
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

                    // count doesn't work
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
    queue.addAssignment(c->courseName, names[pick - 1], name); // Change based on new names for structs
    cout << " Added " << name << ".\n";
}

void UI::deleteAssignment() {
    // TO DO
}

void UI::editAssignment() { // Waiting on edit function 
    vector<Assignment> list = queue.sortedAssignments(); // Change based on new names for structs
    if (list.empty()) {
        cout << "No assignments to edit.\n";
        return;
    }

    cout << "Assignments:\n";
    for (size_t i = 0; i < list.size(); i++) {
        cout << i + 1 << ". " << list[i].assignmentName << " (" << list[i].courseName << ", " << list[i].category << ")\n";
    }                                                                //        ^ Change based on new names for structs
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
    } //            ^ Change based on new names for structs

    if (queue.updateAssignment(list[pick - 1], updated)) {
        cout << "  Updated " << updated.assignmentName << ".\n";
    }
    else {
        cout << "  Could not update the assignment.\n";
    }
}

void UI::viewAssignments() const {
    // TO DO
}

void UI::markAssignmentDone() {

}

void UI::viewPriorityList() const {
    vector<Assignment> list = queue.sortedAssignments();
    if (list.empty()) {              // ^ Change based on new names for structs
        cout << "Nothing to do.\n";
        return;
    }
    cout << "Priority list:\n";
    int index = 1;
    for (const auto& item : list) {
        cout << index++ << ". " << item.assignmentName << " (" << item.courseName << ", " << item.category << ")\n";
        cout << "   Priority: " << item.priority << "\n";                // ^ Change based on new names for structs
    }
}

void UI::saveManually() {
    // TO DO
}

void UI::completeNext() {
    vector<Assignment> list = queue.sortedAssignments();
    if (list.empty()) {                  // ^ Change based on new names for structs
        cout << "Nothing to mark done.\n";
        return;
    }
    for (size_t i = 0; i < list.size(); i++) {
        cout << i + 1 << ". " << list[i].assignmentName << " (" << list[i].courseName << ")\n";
    }                                                                        // ^ Change based on new names for structs
    cout << "\n";
    int pick = (int)getNumberInRange("Which one is done? ", 1, list.size());
    Assignment chosen = list[pick - 1];
    queue.markDone(chosen.courseName, chosen.assignmentName);  // <- Change based on new names for structs
                             // ^ Change based on new names for structs
    cout << "  Done: " << chosen.assignmentName << " (" << chosen.courseName << ")\n";
                                                                //  ^ Change based on new names for structs
}
