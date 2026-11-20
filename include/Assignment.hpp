#ifndef ASSIGNMENT
#define ASSIGNMENT

#include <iostream>
#include <map>
using std::string;
using std::map;


struct Course {
	//stores the types of assignments in the course
	string courseName;
	double currentGrade;
	map<string, double> categories;

};

struct Assignment {
	string courseName;
	string assignmentName;
	string category;
	int estimatedWorth;

	//calculated based on other values
	int priority;
};

bool operator< (Assignment& lhs, Assignment& rhs) {
	return lhs.priority < rhs.priority;
}

bool operator== (Assignment& lhs, Assignment& rhs) {
	return lhs.priority == rhs.priority;
}

#endif