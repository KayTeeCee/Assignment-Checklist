#include "Assignment.hpp"

Assignment(string inputName, int dueYear, int dueMonth, int dueDay) : assignmentName(inputName), is_done(false) {
	dueDate = std::chrono::year_month_day(std::chrono::year(dueYear), std::chrono::month(dueMonth), std::chrono::day(dueDay));
}

void Assignment::updatePriority(){
	
}

bool operator< (Assignment& lhs, Assignment& rhs) {return lhs.priority < rhs.priority;}
bool operator== (Assignment& lhs, Assignment& rhs) {return lhs.priority == rhs.priority;}
