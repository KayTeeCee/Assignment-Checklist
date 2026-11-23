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
    string catName;                    // Category name
    double catValue;                   // Percent of total grade (1.00/100%) that this category is worth (ex. Homework, 0.25 (25%))
    vector<Assignment> assignments;    // Assignments that are part of this category

    Course* course;                    // To access the course this category is in

    // friend classes declarations
    friend class Course;
    friend class Assignment;

public:
    Category(Course* currCourse, string inputName, double inputValue);
    void addAssignment(string asName, int inputPoints, int dueYear, int dueMonth, int dueDay);
    void markAssignmentDone(string asName);
};
#endif
