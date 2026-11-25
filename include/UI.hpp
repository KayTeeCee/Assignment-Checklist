#ifndef UI_HPP
#define UI_HPP

#include "AssignmentQueue.hpp"

class UI {
public:
    explicit UI(AssignmentQueue& q) : queue(q) {}
    void run();

private:
    AssignmentQueue& queue;

////// Main Menu ///////////////////////////
    void showMenu() const;
    void doMenu();
    void viewPriorityList() const;
    void saveManually();
    // Quit
    ////+ below

////// Courses /////////////////////////////
    void showCourseOptions() const;
    void doCourseOptions();

    // Options
    void addCourse(); // 1
    void deleteCourse(); // 2
    void editCourse(); // 3 TO DO
    void showCourseEditOptions() const;
    void doCourseEditOptions(Course* c);

    void editCourseName(Course* c);
    void editCourseGrade(Course* c);
    void editGradeRange(Course* c);
    void categoryOptions(Course* c); // TO DO

    void viewCourses() const; // 4
    // Back to Main Menu 5

////// Assignments /////////////////////////
    void showAssignmentOptions() const;
    void doAssignmentOptions();

    // Options
    void addCategory();
    void editLetterCutoff();

    void addAssignment();
    void deleteAssignment();
    void editAssignment();
    void viewAssignments() const;
    void markAssignmentDone();
    void completeNext();

    // Back to Main Menu

////// Other Functions //////////////////////
    Course* chooseCourse();
};

#endif
