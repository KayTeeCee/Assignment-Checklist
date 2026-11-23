#include "Course.hpp"

Course::Course(string name, double grade = 100.00) : letterRange{0.90,0.80,0.70,0.60}, courseName(name), courseGrade(grade) {
    categories.push_back(new Category("defualt", 1.00, 0); // <- defualt 1 category for 100% (should delete once we add more)
}

void Course::addCategory(string name, double points){
    // To get rid of default category if it exists
    if (categories.size() == 1 && categories[0].name == "defualt") {
        categories.pop_back();
    }
    // Add the category we want to add to the vector of categories
    categories.push_back(new Category(name, points, 0);
}

void Course::removeCategory(string name){
    // Removes "all" categories with the name, (we don't let creation of multiple categories with the same name)
    std::erase_if(categories, [&](const Category& category) {return category.name == name;});
}

bool Course::verifyCategories(){
        double total = 0.0;
        for(Category& category : categories){
            //iterate through categories
            total += category.value;
        }
        return total == 1.0;
}

bool Course::setLowerBound(char letter, double newLowerBound){
        if(letter >= 'A' && letter <= 'D'){
            double minimum = 0.00;
            double maximum = 1.00;
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
