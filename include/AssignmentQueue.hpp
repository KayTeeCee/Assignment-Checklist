#ifndef ASSIGNMENT_QUEUE
#define ASSIGNMENT_QUEUE

#include "Course.hpp"
#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;
using std::string;

class AssignmentQueue {
private:
    vector<Course> courses;
    priority_queue<Assignment> queue;

public:
    AssignmentQueue();

    void addCourse(const Course& c);
    bool removeCourse(const string& courseName);
    vector<Course>& getCourses();
    const vector<Course>& getCourses() const;
    void addAssignment(Assignment a);
    bool updateAssignment(const Assignment& oldItem, const Assignment& updatedItem);
    bool empty() const;
    Assignment popNext();

    void setCourseGrade(string name, double grade);
    char getCourseLetterGrade(string name);

    //assignment related functions
    void addAssignment(string courseName, string assignmentName);
    void markDone(string assignmentName);

    //save/load functions
    void save();
    void saveCourseList();
    void saveAssignmentList();

    void load();
    void loadCourseList();
    void loadAssignmentList();
};


#endif
