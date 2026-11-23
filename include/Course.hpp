#ifndef COURSE
#define COURSE

#include <iostream>
#include <map>

using std::string;
using std::map;


struct Course {
	//stores the types of assignments in the course
	string courseName;
    //current grade of the class in % up to 100
	double currentGrade;
    //stores the portion of the total grade each category is worth, up to 1.0
	map<string, double> categories;
    //stores the lower bound of each letter grade
    double letterRange[4];

    //no default name, grade defaults to 100.00, letter ranges default to 90-60%, decrementing in 10s, categories defaults to Assignments at 100%
    Course(string name, double grade = 100.00) : letterRange{0.90,0.80,0.70,0.60}{
        courseName = name;
        currentGrade = grade;

        categories = map<string,double>();
        categories.insert_or_assign("Assignments", 1.0);
    }
    
    void addCategory(string name, double points);
    void removeCategory(string name);
    bool verifyCategories();
    bool setLowerBound(char letter, double newLowerBound);
};

#endif