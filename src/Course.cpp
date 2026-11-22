#include "Course.hpp"

void Course::addCategory(string name, double points){
    categories.insert_or_assign(name, points);
}

void Course::removeCategory(string name){

}

bool Course::verifyCategories(){
        double total = 0.0;
        for(auto category = categories.begin(); category != categories.end();category++){
            //iterate through categories
            total += category->second;
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



