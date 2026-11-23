#ifndef UI_HPP
#define UI_HPP

#include "AssignmentQueue.hpp"

class UI {
public:
    explicit UI(AssignmentQueue& q) : queue(q) {}
    void run();

private:
    AssignmentQueue& queue;

    void showMenu() const;
    void addCourse();
    void deleteCourse();
    void showCourses() const;
    void addCategory();
    void editLetterCutoff();
    void addAssignment();
    void editAssignment();
    void showPriorityList() const;
    void completeNext();

    Course* chooseCourse();
};

#endif
