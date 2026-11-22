#ifndef ASSIGNMENT
#define ASSIGNMENT

#include <iostream>
#include <map>
using std::string;
using std::map;



struct Assignment {
	string courseName;
	string assignmentName;
	string category;

	//calculated based on other values
	int priority;
};

bool operator< (Assignment& lhs, Assignment& rhs);

bool operator== (Assignment& lhs, Assignment& rhs);
#endif