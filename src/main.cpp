#include "Assignment.hpp"
#include "Course.hpp"

#include <iostream>

using std::string;

int main(){
    Course test = Course("name");
    test.setLowerBound('B', 0.850);
    for(char letter = 'A'; letter < 'E'; letter++){
        std::cout << letter << ": " << test.letterRange[letter - 'A'] << "\n";
    }

    test.addCategory("Homework", 0.25);
    test.addCategory("LeetCode", 0.20);
    test.addCategory("Midterm", 0.15);
    test.addCategory("Project", 0.20);
    test.addCategory("Final", 0.20);
    std::cout << "\n" << test.verifyCategories();
    
    std::chrono::year_month_day due(std::chrono::year(2026)/std::chrono::November/std::chrono::day(4));
    Assignment asn = Assignment("name","Test Assignment", "Homework", 2026, 11, 15);
    asn.updatePriority();

    return 0;
}
