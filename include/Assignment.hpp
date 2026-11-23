#ifndef ASSIGNMENT
#define ASSIGNMENT

#include <iostream>
#include <map>
#include <chrono>

using std::string;
using std::map;

struct Assignment {
    Assignment(string course, string name, string category, int dueYear, int dueMonth, int dueDay){
        courseName = course;
        assignmentName = name;
        this->category = category;
        dueDate = std::chrono::year_month_day(std::chrono::year(dueYear), std::chrono::month(dueMonth), std::chrono::day(dueDay));
    }


    void updatePriority();

	string courseName;
	string assignmentName;
	string category;
    std::chrono::year_month_day dueDate;
	//calculated based on other values
	int priority;

    //overload assignment operators to use priority value for priority queue
    friend bool operator< (Assignment& lhs, Assignment& rhs);
    friend bool operator== (Assignment& lhs, Assignment& rhs);
};


#endif