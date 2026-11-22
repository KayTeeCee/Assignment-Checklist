#ifndef ASSIGNMENT_QUEUE
#define ASSIGNMENT_QUEUE

#include "Assignment.hpp"
#include "Course.hpp"
#include <queue>

using std::priority_queue;

class AssignmentQueue {
private:
    std::vector<Course> courses;
    priority_queue<Assignment> queue;

public:

    //course related functions
    void addCourse(string name);
    //also remove assignments for that course
    void deleteCourse(string name);
    void setCourseGrade(string name, double grade);
    char getCourseLetterGrade(string name);




    //assignment related functions
    void addAssignment(string courseName, string assignmentName);
    void markDone(string assignmentName);

};


#endif