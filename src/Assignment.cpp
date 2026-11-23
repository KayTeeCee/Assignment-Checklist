#include "Assignment.hpp"

Assignment(string inputName, int inputValue, int dueYear, int dueMonth, int dueDay) : asName(inputName), asValue(inputValue), is_done(false) {
	dueDate = std::chrono::year_month_day(std::chrono::year(dueYear), std::chrono::month(dueMonth), std::chrono::day(dueDay));
	updatePriority();
}

void Assignment::updatePriority(){
	// Example equation
	// priority = (100-dueDate) / (100-point_value) + courseGrade;
}

bool operator< (Assignment& lhs, Assignment& rhs) {return lhs.priority < rhs.priority;}
bool operator== (Assignment& lhs, Assignment& rhs) {return lhs.priority == rhs.priority;}
