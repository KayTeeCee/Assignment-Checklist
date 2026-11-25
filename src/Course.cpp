#include "Course.hpp"

Course::Course(string name, double grade = 100.00) : letterRange{90.0,80.0,70.0,60.0}, courseName(name), currentGrade(grade) {
    categories.push_back(new Category("default", 100.0)); // <- defualt 1 category for 100% (overwrite once we add more)
}

//O(n)
void Course::addOrEditCategory(string name, double points){
    //overwrite default category
    if(categories.at(0)->name == "default"){
        categories.at(0)->name = name;
        categories.at(0)->value = points;
        return;
    }

    //overwrite existing category with same name, if exists
    int i = findCategory(name);
    if(i != -1){
        categories.at(i)->value = points;
        return;
    }

    // Add the category we want to add to the vector of categories
    categories.push_back(new Category(name, points));
}


void Course::removeCategory(string name){
    // Removes "all" categories with the name, (we don't let creation of multiple categories with the same name)
    int i = findCategory(name);
    while(i != -1){
        Category* del = categories.at(i);
        categories.erase(categories.begin() + i);
        delete del;
        i = findCategory(name);
    }
}

bool Course::verifyCategories(){
        double total = 0.0;
        for(Category* category : categories){
            //iterate through categories
            total += category->value;
        }
        return total == 100.0;
}

bool Course::setLowerBound(char letter, double newLowerBound){
        if(letter >= 'A' && letter <= 'D'){
            double minimum = 0.00;
            double maximum = 100.0;
            if(letter != 'D'){
                minimum = letterRange[letter + 1 - 'A'];
            }
            if(letter != 'A'){
                maximum = letterRange[letter - 1 - 'A'];
            }

            if(minimum < newLowerBound && maximum > newLowerBound){
                letterRange[letter - 'A'] = newLowerBound;
                return true;
           }
        }
        return false;
}

int Course::findCategory(string name){
    for(int i = 0; i < categories.size(); i++){
        if(categories.at(i)->name == name){
            return i;
        }
    }
    return -1;
}
