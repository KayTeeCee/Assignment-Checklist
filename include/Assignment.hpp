#ifndef ASSIGNMENT
#define ASSIGNMENT

#include <iostream>
#include <chrono>

struct Category;
struct Course;

using std::string;

struct Assignment {
	string assignmentName;	// <- Name of this assignment
	Category *category;	// <- Category it is contained in
    int dueDate[3];	// <- Stored as (year, month, day)
	int priority;	// <- Calculated based on other values
    bool isComplete;

	// Constructor
    Assignment(string name, Category *category, int dueDate[3]);

	// Calculate priority based on due date, course grade, and assignment value, using custom equation
    void updatePriority();

    

    // Overload assignment operators to use priority value for priority queue
    friend bool operator< (Assignment& lhs, Assignment& rhs);
    friend bool operator== (Assignment& lhs, Assignment& rhs);
};
#endif
