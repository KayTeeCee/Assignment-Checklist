#include "AssignmentQueue.hpp"

AssignmentQueue() {
    courses = vector<Course>();
    queue = priority_queue<Assignment>();
}

void addCourse(const Course& c)
{
    
}

bool removeCourse(const std::string& courseName)
{
    
}

vector<Course>& getCourses()
{
    
}

const vector<Course>& getCourses() const
{
    
}

void addAssignment(Assignment a)
{
    
}

bool updateAssignment(const Assignment& oldItem, const Assignment& updatedItem)
{
    
}

bool empty() const
{
    
}

Assignment popNext()
{
    
}


void setCourseGrade(string name, double grade)
{
    
}

char getCourseLetterGrade(string name)
{
    
}
     
//assignment related functions
void addAssignment(string courseName, string assignmentName)
{
    
}
    
void markDone(string assignmentName)
{
    
}

//save/load functions
void save()
{
    // Create the file variable for inputting using the file stored in "data" repository
    ifstream inData;
    inData.open("data/data.csv");

    // Load courses and assignments in the file respectively (using the following functions)
    this->saveCourseList();
    this->saveAssignmentList();

    // Close file when we're done with it
    inData.close();
}

void saveCourseList()
{
    for (Course& course : courses) {
        
    }
}

void saveAssignmentList()
{
      
}


void load()
{
    // Create the file variable for outputting using the file stored in "data" repository
    ofstream outData;
    outData.open("data/data.csv")

    // Load courses and assignments in the file respectively (using the following functions)
    this->loadCourseList();
    this->loadAssignmentList();

    // Close file when we're done with it
    outData.close();
}

void loadCourseList()
{
      
}

void loadAssignmentList()
{
      
}
