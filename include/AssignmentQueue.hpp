#ifndef ASSIGNMENT_QUEUE
#define ASSIGNMENT_QUEUE

#include "Assignment.hpp"
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

    void addCourse(string inputName);
    bool removeCourse(const string& courseName);
    vector<Course>& getCourses();
    const vector<Course>& getCourses() const;
    bool empty() const;
    Assignment popNext();

    void setCourseGrade(string name, double grade);
    char getCourseLetterGrade(string name);

    //assignment related functions
    void addAssignment(string inputCourse, string inputCategory, string inputAssignment, int value, int dueYear, int dueMonth, int dueDay);
    bool updateAssignment(const Assignment& oldItem, const Assignment& updatedItem);
    void markDone(string assignmentName);

    //save/load functions
    void save();
    void load();
};


#endif
