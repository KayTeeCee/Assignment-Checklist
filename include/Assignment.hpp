#ifndef ASSIGNMENT
#define ASSIGNMENT

#include <iostream>
#include <map> // <-- are we still using map?
#include <chrono>

using std::string;
using std::map;

struct Assignment {
	string asName;	// <- Name of this assignment
	int asValue;	// <- in points
    std::chrono::year_month_day dueDate;	// <- Stored as (year, month, day)
	bool is_done;	// <- whether the assignment has been completed or not (for course grade calculation)
	int priority;	// <- Calculated based on other values

	// Constructor
    Assignment(string inputName, int inputValue, int dueYear, int dueMonth, int dueDay);

	// Calculate priority based on due date, course grade, and assignment value, using custom equation
    void updatePriority();

    // Overload assignment operators to use priority value for priority queue
    friend bool operator< (Assignment& lhs, Assignment& rhs);
    friend bool operator== (Assignment& lhs, Assignment& rhs);
};
#endif
