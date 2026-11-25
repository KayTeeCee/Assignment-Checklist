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
    cout << "4. Save\n";
    cout << "0. Save and quit\n";
    cout << "-------------------------------\n";
}

// Do Main Menu
void UI::doMenu() {
    int choice;
    do {
        showMenu();
        choice = (int)getNumberInRange("Choose an option: ", 0, 4);
        cout << "\n";
        switch (choice) {
        case 1: doCourseOptions(); break;
        case 2: doAssignmentOptions(); break;
        case 3: viewPriorityList(); break;
        case 4: saveManually(); break;
        case 0: saveManually(); break;
        }
    } while (choice != 0);
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
    int choice;
    do {
        showCourseOptions();
        choice = (int)getNumberInRange("Choose an option: ", 1, 5);
        cout << "\n";
        switch (choice) {
        case 1: addCourse(); break;
        case 2: deleteCourse(); break;
        case 3: editCourse(); break;
        case 4: viewCourses(); break;
        case 5: break;
        }
        cout << "\n";
    } while (choice != 5);
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
    int choice;
    do {
        showAssignmentOptions();
        choice = (int)getNumberInRange("Choose an option: ", 1, 6);
        cout << "\n";

        switch (choice) {
        case 1: addAssignment(); break;
        case 2: deleteAssignment(); break;
        case 3: editAssignment(); break;
        case 4: viewAssignments(); break;
        case 5: markAssignmentDone(); break;
        case 6: break;
        }

        std::cout << "\n";
    } while (choice != 6);
}

void UI::addCourse() {
    string name = getNonEmptyLine("Course name: ");
    const vector<Course*>& courses = queue.getCourses();
    for (const Course* course : courses) {
        if (course->courseName == name) {
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
    int choice;
    do {
        showCourseEditOptions();
        choice = (int)getNumberInRange("Choose an option: ", 1, 5);
        cout << "\n";
        switch (choice) {
        case 1: editCourseName(c); break;
        case 2: editCourseGrade(c); break;
        case 3: categoryOptions(c); break;
        case 4: editGradeRange(c); break;
        case 5: break; // Go back up one menu
        }
        std::cout << "\n";
    } while (choice != 5);
}

void UI::editCourseName(Course* c) {
    string new_name = getNonEmptyLine("New course name: ");
    c->courseName = new_name;
}

void UI::editCourseGrade(Course* c) {
    c->currentGrade = getNumberInRange("New course grade in percent: ", 0, 100);
}

void UI::editGradeRange(Course* c) {
    string input = getNonEmptyLine("Letter (A-D): ");
    char letter = (char)std::toupper(input[0]);
    if (input.length() != 1 || letter < 'A' || letter > 'D') {
        cout << " Enter a single letter: A, B, C, or D.\n";
        return;
    }
    double percent = getNumberInRange("New minimum percent: ", 0, 100);
    if (c->setLowerBound(letter, percent))
        cout << " Updated.\n";
    else
        cout << " Not updated, it has to stay between the letters above and below it.\n";
}

void UI::showCategoryOptions() const {
    cout << "-------------------------------\n";
    cout << "1. Add a category\n";
    cout << "2. Remove a category\n";
    cout << "3. Back\n";
    cout << "-------------------------------\n";
}

void UI::categoryOptions(Course* c) {
    int choice;
    do {
        showCategoryOptions();
        choice = (int)getNumberInRange("Choose an option: ", 1, 3);
        cout << "\n";
        switch (choice) {
        case 1: addCategory(c); break;
        case 2: removeCategory(c); break;
        case 3: break;
        }
        cout << "\n";
    } while (choice != 3);
}

void UI::viewCourses() const {
    const vector<Course*>& courses = queue.getCourses();
    if (courses.empty()) {
        cout << "No courses yet.\n";
        return;
    }

    bool first = true;
    for (const Course* c : courses) {
        if (!first) cout << "\n";
        first = false;

        cout << c->courseName << "\n";
        for (int i = 0; i < 4; i++) {
            cout << "  " << char('A' + i) << " starts at " << c->letterRange[i] << "%\n";
        }

        if (c->categories.size() == 1 && c->categories[0]->name == "default") {
            cout << "  No categories added yet.\n";
        }
        else {
            for (const Category* cat : c->categories) {
                cout << "  " << cat->name << ": " << cat->value << "%\n";
            }
        }
    }
}

Course* UI::chooseCourse() {
    vector<Course*>& courses = queue.getCourses();
    if (courses.empty()) {
        cout << "No courses added yet.\n";
        return nullptr;
    }
    cout << "Courses:\n";
    for (size_t i = 0; i < courses.size(); i++) {
        cout << i + 1 << ". " << courses[i]->courseName << "\n";
    }
    cout << "\n";
    int pick = (int)getNumberInRange("Pick a course: ", 1, courses.size());
    return courses[pick - 1];
}

void UI::addCategory(Course* c) {
    string name = getNonEmptyLine("Category name: ");
    if (c->findCategory(name) != -1) {
        cout << "  This category already exists in " << c->courseName << ".\n";
        return;
    }

    double percent = getNumberInRange("Weight in percent: ", 0, 100);
    c->addOrEditCategory(name, percent);

    double total = 0.0;
    for (const Category* cat : c->categories) {
        total += cat->value;
    }

    // Weight validation
    if (c->verifyCategories()) {
        cout << "  Weights now add up to 100%.\n";
    }
    else if (total > 100.0) {
        cout << "  Category weights exceed 100%.\n";
    }
    else {
        cout << "  Saved. Weights don't add up to 100% yet.\n";
    }
}

void UI::removeCategory(Course* c) {
    if (c->categories.size() == 1 && c->categories[0]->name == "default") {
        cout << "  No categories to remove.\n";
        return;
    }

    cout << "Categories:\n";
    for (size_t i = 0; i < c->categories.size(); i++) {
        cout << i + 1 << ". " << c->categories[i]->name << " (" << c->categories[i]->value << "%)\n";
    }
    cout << "\n";

    int pick = (int)getNumberInRange("Pick a category to remove: ", 1, c->categories.size());
    string name = c->categories[pick - 1]->name;
    c->removeCategory(name);
    cout << "  Removed " << name << ".\n";
}

void UI::addAssignment() {
    Course* c = chooseCourse();
    if (c == nullptr) return;

    if (c->categories.size() == 1 && c-> categories[0]->name == "default") {
        cout << "  This course has no categories yet. Add one in course options.\n";
        return;
    }

    vector<string> names;
    for (const Category* cat : c->categories) {
        names.push_back(cat->name);
    }
    cout << "Categories:\n";
    for (size_t i = 0; i < names.size(); i++) {
        cout << i + 1 << ". " << names[i] << "\n";
    }
    cout << "\n";
    int pick = (int)getNumberInRange("Pick a category: ", 1, names.size());

    string name = getNonEmptyLine("Assignment name: ");
    double points = getNumberInRange("Points: ", 0, 10000);
    int year = (int)getNumberInRange("Due year: ", 2000, 2100);
    int month = (int)getNumberInRange("Due month (1-12): ", 1, 12);
    int day = (int)getNumberInRange("Due day (1-31): ", 1, 31);
    queue.addAssignment(c->courseName, names[pick - 1], name, points, year, month, day); // Change based on new names for structs
    cout << " Added " << name << ".\n";
}

void UI::deleteAssignment() {
    // TO DO waiting on removeAssignment in AssignmentQueue
}

void UI::editAssignment() { // Waiting on edit function 
    vector<Assignment> list = queue.sortedAssignments(); // Change based on new names for structs
    if (list.empty()) {
        cout << "No assignments to edit.\n";
        return;
    }

    cout << "Assignments:\n";
    for (size_t i = 0; i < list.size(); i++) {
        cout << i + 1 << ". " << list[i].assignmentName << " (" << list[i].courseName << ", " << list[i].category->name << ")\n";
    }                                                                //        ^ Change based on new names for structs
    cout << "\n";

    int pick = (int)getNumberInRange("Pick an assignment: ", 1, list.size());
    Assignment updated = list[pick - 1];

    cout << "1. Edit name\n";
    cout << "2. Edit points\n";
    cout << "3. Edit due date\n";
    int field = (int)getNumberInRange("What do you want to change? ", 1, 3);

    if (field == 1) {
        updated.assignmentName = getNonEmptyLine("New assignment name: ");
    }
    else if (field == 2) {
        updated.points = getNumberInRange("New points: ", 0, 100000); 
    } //            ^ Change based on new names for structs
    else {
        updated.dueDate[0] = (int)getNumberInRange("New due year: ", 2000, 2100);
        updated.dueDate[1] = (int)getNumberInRange("New due month (1-12): ", 1, 12);
        updated.dueDate[2] = (int)getNumberInRange("New due day (1-31): ", 1, 31);
    }
    if (queue.updateAssignment(list[pick - 1], updated)) { // Change based on new names for structs
        cout << "  Updated " << updated.assignmentName << ".\n";
    }
    else {
        cout << "  Could not update the assignment.\n";
    }
}


void UI::viewAssignments() const {
    const vector<Course*>& courses = queue.getCourses();
    if (courses.empty()) {
        cout << "No courses yet.\n";
        return;
    }

    for (const Course* c : courses) {
        cout << c->courseName << "\n";

        for (const Category* cat : c->categories) {
            cout << cat->name << ":\n";

            if (cat->assignments.empty()) {
                cout << "No assignments yet.\n";
                continue;
            }

            for (const Assignment* a : cat->assignments) {
                cout << a->assignmentName
                    << " | " << a->points << " pts"
                    << " | due " << a->dueDate[1] << "/" << a->dueDate[2] << "/" << a->dueDate[0]
                    << (a->isComplete ? " | done" : " | not done") << "\n";
            }
        }
        cout << "\n";
    }
}

void UI::markAssignmentDone() {
    vector<Assignment> list = queue.sortedAssignments(); 
    if (list.empty()) {                  // ^ Change based on new names for structs   
        cout << "Nothing to mark done.\n";
        return;
    }

    for (size_t i = 0; i < list.size(); i++) {
        cout << i + 1 << ". " << list[i].assignmentName << " (" << list[i].courseName << ", " << list[i].category->name << ")\n";
    }                                                                        // ^ Change based on new names for structs
    cout << "\n";

    int pick = (int)getNumberInRange("Which one is done? ", 1, list.size());
    Assignment chosen = list[pick - 1];

    queue.markDone(chosen.courseName, chosen.category->name, chosen.assignmentName);    // <- Change based on new names for structs
    // ^ Change based on new names for structs
    cout << "  Done: " << chosen.assignmentName << " (" << chosen.courseName << ")\n";
    //  ^ Change based on new names for structs
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
        cout << index++ << ". " << item.assignmentName << " (" << item.courseName << ", " << item.category->name << ")\n";
        cout << "   Priority: " << item.priority << "\n";                // ^ Change based on new names for structs
    }
}

void UI::saveManually() {
    queue.save();
    cout << " Saved.\n";
}

