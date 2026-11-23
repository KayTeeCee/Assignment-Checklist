#ifndef ASSIGNMENT
#define ASSIGNMENT

#include <iostream>
#include <map> // <-- are we still using map?
#include <chrono>

using std::string;
using std::map;

struct Assignment {
	string assignmentName;	// <- Name of this assignment
	string courseName;  // <- Course it is contained in
	string categoryName;	// <- Category it is contained in
    std::chrono::year_month_day dueDate;	// <- Stored as (year, month, day)
	int priority;	// <- Calculated based on other values

	// Constructor
    Assignment(string course, string name, string category, int dueYear, int dueMonth, int dueDay);

	// Calculate priority based on due date, course grade, and assignment value, using custom equation
    void updatePriority();

    // Overload assignment operators to use priority value for priority queue
    friend bool operator< (Assignment& lhs, Assignment& rhs);
    friend bool operator== (Assignment& lhs, Assignment& rhs);
};
#endif
