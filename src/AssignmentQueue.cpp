#include "AssignmentQueue.hpp"
#include <fstream>

AssignmentQueue::AssignmentQueue() {
    courses = vector<Course*>();
    queue = priority_queue<Assignment*>();
}

void AssignmentQueue::addCourse(const string& inputName)
{
    //dont add duplicate course names
    if(findCourse(inputName) != -1) return;
    courses.push_back(new Course(inputName));
}

bool AssignmentQueue::removeCourse(const string& courseName)
{
    int i = findCourse(courseName);
    while(i != -1){
        Course* del = courses.at(i);
        courses.erase(courses.begin()+i);
        delete del;
    }
}

vector<Course*>& AssignmentQueue::getCourses()
{
    return courses;
}

bool AssignmentQueue::empty() const
{
    
}

Assignment AssignmentQueue::popNext()
{
    Assignment to_return = queue.top();
    queue.pop();
    return to_return;
}

void AssignmentQueue::setCourseGrade(string name, double grade)
{
    
}

char AssignmentQueue::getCourseLetterGrade(string name)
{
     // Find correct course
    for (Course& course, courses) {
        if (course.courseName == inputCourse) {

            // Implementation for converting double current grade to letter grade
            return course.
        }
    }
}
     
//assignment related functions
void AssignmentQueue::addAssignment(string inputCourse, string inputCategory, string inputAssignment, int value, int dueYear, int dueMonth, int dueDay)
{
    // Find correct course
    for (Course& course, courses) {
        if (course.courseName == inputCourse) {

            // Find correct category
            for (Category& category : course.categories) {
                if (category.catName == inputCategory) {

                    // Add the Assignment to corresponding category within corrsponding course
                    category.addAssignment(inputAssignment, value, dueYear, dueMonth, dueDay);
                    break;
                }
            }
        }
    }
}

bool AssignmentQueue::updateAssignment(const Assignment& oldItem, const Assignment& updatedItem)
{
    // Use similary code from addAssignment (find assignment to edit using name, then update the rest of the values)
}
    
void AssignmentQueue::markDone(string courseName, string categoryName, string assignmentName)
{
    // Find correct course
    for (Course& course, courses) {
        if (course.courseName == inputCourse) {

            // Find correct category
            for (Category& category : course.categories) {
                if (category.catName == inputCategory) {

                    // Mark the assignment as done
                    category.markAssignmentDone(string asName);
                    break;
                }
            }
        }
    }
}

//save/load functions
void AssignmentQueue::save()
{
    // Create the file variable for writing using the file stored in "data" repository
    ofstream inData("data/data.csv");

    for (Course& course : courses) {
        inData << course.courseName << ',' << course.currentGrade;
        
        for (Category& category : course.categories) {
            inData << ',' << '>' << category.name << ',' << category.value;
            
            for (Assignment& assignment : category.assignments) {
                inData << ',' << assignment.asName << ',' << assignment.asValue << ',' << static_cast<int>((assignment.dueDate).year()) << ',' << static_cast<unsigned>((assignment.dueDate).month()) << ',' << static_cast<unsigned>((assignment.dueDate).day());
            }
        }
        inData << '\n';
    }

    // Close file when we're done with it
    inData.close();
}

void AssignmentQueue::load()
{
    // Create the file variable for reading using the file stored in "data" repository
    ifstream outData("data/data.csv");

    while (

    // Close file when we're done with it
    outData.close();
}
