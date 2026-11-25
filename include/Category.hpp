#ifndef CATEGORY
#define CATEGORY

#include "Assignment.hpp"
#include <iostream>
#include <vector>


using std::string;

struct Category {
    string name;
    double value; // % out of 100.0
    std::vector<Assignment*> assignments; // store all assignments within category
    Category(string inputName, double inputValue) : name(inputName), value(inputValue) {
        assignments = std::vector<Assignment*>();
    }
    ~Category(){
        //delete all assignments
        while(!assignments.empty()){
            Assignment* cur = assignments.back();
            assignments.pop_back();
            delete cur;
        }
    }
};
#endif
