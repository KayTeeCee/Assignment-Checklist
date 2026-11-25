#include "Assignment.hpp"

Assignment::Assignment(string name, Category *category, int dueDate[3]){
	assignmentName = name;
	this->category = category;
	dueDate[0] = dueDate[0];
	dueDate[1] = dueDate[1];
	dueDate[2] = dueDate[2];
	priority = 0;
	isComplete = false;
	updatePriority();
}


void Assignment::updatePriority(){
	//implement later, need to fix broken parts first
}

bool operator< (Assignment& lhs, Assignment& rhs) {
	return lhs.priority < rhs.priority;
}


bool operator== (Assignment& lhs, Assignment& rhs) {
	return lhs.priority == rhs.priority;
}
