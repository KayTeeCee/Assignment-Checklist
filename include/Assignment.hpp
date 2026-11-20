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
    //stores the lower bound of each letter grade
    map<char, double> letterRange;

    Course(string name, double grade = 100.00){
        courseName = name;
        currentGrade = grade;

        categories = map<string,double>();

        letterRange = map<char, double>();
        double min = 90.00;
        for(char letter = 'A'; letter < 'E'; letter++){
            letterRange.insert_or_assign(letter, min);
            min -= 10.0;
        }
    }

    void addCategory(string name, double points){
        categories.insert_or_assign(name, points);
    }
    bool verifyCategories(){
        double total = 0.0;
        for(auto category = categories.begin(); category != categories.end();category++){
            //iterate through categories
            total += category->second;
        }
        return total == 1.0;
    }

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