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
    vector<Course*> courses;
    priority_queue<Assignment*> queue;

public:
    AssignmentQueue();

    void addCourse(const string& name);
    bool removeCourse(const string& courseName);
    void renameCourse(const string& currentName, const string& newName);
    void setCourseGrade(const string& name, double grade);
    void setCourseLetterGrade(const string& name, char letter, int newLowerBound);
    char getCourseLetterGrade(const string& name);
    void deleteCourse(const string& name);
    void addOrEditCategory(const string& course, const string& category, double value);

    
    vector<Course*>& getCourses();
    int findCourse(string name);

    void addAssignment(Assignment a);
    bool updateAssignment(Assignment* oldItem, const Assignment* updatedItem);
    bool empty() const;
    Assignment popNext();

    

    //assignment related functions
    void addAssignment(string courseName, string assignmentName);
    void markDone(string assignmentName);

    // TO DO
    // For UI to delete an assignment. Removes assignment from its category and queue. Returns false if not found
    bool removeAssignment(const string& courseName, const string& categoryName, const string& assignmentName); 

    //save/load functions
    void save();
    void saveCourseList();
    void saveAssignmentList();

    void load();
    void loadCourseList();
    void loadAssignmentList();
};


#endif
