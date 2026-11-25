#include <iostream>
#include "Ui.hpp"
#include "AssignmentQueue.hpp"

using std::string;

int main() 
{
    // Create Q
    AssignmentQueue myQ;

    // Create UI object
    UI program(myQ);

    // Run program
    program.run();

    return 0;
}
