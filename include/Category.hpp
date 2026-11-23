#ifndef CATEGORY
#define CATEGORY

#include <iostream>
#include <string>
#include <vector>

#include "Assignment.hpp"
#include "Course.hpp"

using std::string;
using std::vector;

class Course;        // forward declaration for inheritance
class Assignment;    // forward declaration for inheritance

class Category {
private:
    string catName;
    double catValue;
    vector<Assignment> assignments;

    Course* course;
    friend class Course;
    friend class Assignment;
public:
    Category(Course* currCourse, string inputName, double inputValue, int inputNumAssignments) : course(currCourse), catName(inputName), catValue(inputValue), catNumAssignments(inputNumAssignments) {}
    void addAssignment(string asName, int dueYear, int dueMonth, int dueDay);
    void markAssignmentDone(string asName);
};
#endif
