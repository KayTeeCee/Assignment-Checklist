#ifndef COURSE
#define COURSE

#include <iostream>
#include <map>

using std::string;
using std::map;


struct Course {
	//stores the types of assignments in the course
	string courseName;
	double currentGrade;
    //stores the portion of the total grade each category is worth
	map<string, double> categories;
    //stores the lower bound of each letter grade
    double letterRange[4];

    //no default name, grade defaults to 100.00, letter ranges default to 90-60%, decrementing in 10s
    Course(string name, double grade = 100.00) : letterRange{0.90,0.80,0.70,0.60}{
        courseName = name;
        currentGrade = grade;

        categories = map<string,double>();
    }

    void addCategory(string name, double points);
    void removeCategory(string name);
    bool verifyCategories();
    bool setLowerBound(char letter, double newLowerBound);
};

#endif