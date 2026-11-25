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
    void editCourse(); // 3 
    void showCourseEditOptions() const;
    void doCourseEditOptions(Course* c);

    void editCourseName(Course* c);
    void editCourseGrade(Course* c);
    void editGradeRange(Course* c);

    void showCategoryOptions() const;
    void categoryOptions(Course* c); 
    void addCategory(Course* c);
    void removeCategory(Course* c);

    void viewCourses() const; // 4
    // Back to Main Menu 5

////// Assignments /////////////////////////
    void showAssignmentOptions() const;
    void doAssignmentOptions();

    void addAssignment();
    void deleteAssignment();
    void editAssignment();
    void viewAssignments() const;
    void markAssignmentDone();

    // Back to Main Menu

////// Other Functions //////////////////////
    Course* chooseCourse();
};

#endif
