#include "AssignmentQueue.hpp"
#include <fstream>

AssignmentQueue() {
    courses = vector<Course>();
    queue = priority_queue<Assignment>();
}

void addCourse(string inputName)
{
    courses.push_back(new Course(inputName));
}

bool removeCourse(const std::string& courseName)
{
    std::erase_if(courses, [&](const Category& courses) {return courses.courseName == courseName;});
}

vector<Course>& getCourses()
{
    return courses;
}

const vector<Course>& getCourses() const
{
    return courses;
}

bool empty() const
{
    
}

Assignment popNext()
{
    Assignment to_return = queue.top();
    queue.pop();
    return to_return;
}

void setCourseGrade(string name, double grade)
{
    
}

char getCourseLetterGrade(string name)
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
void addAssignment(string inputCourse, string inputCategory, string inputAssignment, int value, int dueYear, int dueMonth, int dueDay)
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

bool updateAssignment(const Assignment& oldItem, const Assignment& updatedItem)
{
    // Use similary code from addAssignment (find assignment to edit using name, then update the rest of the values)
}
    
void markDone(string courseName, string categoryName, string assignmentName)
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
void save()
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

void load()
{
    // Create the file variable for reading using the file stored in "data" repository
    ifstream outData("data/data.csv");

    while (

    // Close file when we're done with it
    outData.close();
}
