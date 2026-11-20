#include "Assignment.hpp"

int main(){
    Course test = Course("name");
    test.setLowerBound('B', 0.850);
    for(char letter = 'A'; letter < 'E'; letter++){
        std::cout << letter << ": " << test.letterRange.at(letter) << "\n";
    }
    test.addCategory("Homework", 0.25);
    test.addCategory("LeetCode", 0.20);
    test.addCategory("Midterm", 0.15);
    test.addCategory("Project", 0.20);
    test.addCategory("Final", 0.20);
    std::cout << "\n" << test.verifyCategories();




    return 0;
}
