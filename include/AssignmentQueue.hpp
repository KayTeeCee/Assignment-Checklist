#ifndef ASSIGNMENT_QUEUE
#define ASSIGNMENT_QUEUE

#include "Assignment.hpp"
#include <queue>
#include <vector>

using std::priority_queue;

class AssignmentQueue {
private:
    std::vector<Course> courses;
    priority_queue<Assignment> queue;

public:
    void addCourse(const Course& c);
    bool removeCourse(const std::string& courseName);
    std::vector<Course>& getCourses();
    const std::vector<Course>& getCourses() const;
    void addAssignment(Assignment a);
    bool updateAssignment(const Assignment& oldItem, const Assignment& updatedItem);
    bool empty() const;
    Assignment popNext();
    std::vector<Assignment> sortedAssignments() const;
};


#endif
