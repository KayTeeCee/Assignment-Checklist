#include "Assignment.hpp"


void Assignment::updatePriority(){
	
}

bool operator< (Assignment& lhs, Assignment& rhs) {
	return lhs.priority < rhs.priority;
}


bool operator== (Assignment& lhs, Assignment& rhs) {
	return lhs.priority == rhs.priority;
}