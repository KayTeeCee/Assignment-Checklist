#ifndef COURSE
#define COURSE

#include <iostream>
#include <vector>
#include "Category.hpp"

using std::string;
using std::vector;

struct Course {
	string courseName;		// <- Stores the types of assignments in the course
	double currentGrade;	// <- Current grade of the class in % up to 100
	vector<Category> categories; // <- Stores the portion of the total grade each category is worth, up to 1.0
    double letterRange[4];  // <- Stores the lower bound of each letter grade

	// Constructor
    // No default name, grade defaults to 100.00, letter ranges default to 90-60%, decrementing in 10s, categories defaults to Assignments at 100%
    Course(string name, double grade = 100.00);
    
    void addCategory(string name, double points);
    void removeCategory(string name);
    bool verifyCategories();
    bool setLowerBound(char letter, double newLowerBound);
};
#endif
