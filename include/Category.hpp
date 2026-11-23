#ifndef CATEGORY
#define CATEGORY

#include <iostream>
#include <string>

using std::string;

struct Category {
    string name;
    double value;
    int numAssignments;
    Category(string inputName, double inputValue, int inputNumAssignments) : name(inputName), value(inputValue), numAssignments(inputNumAssignments) {}
};
#endif
