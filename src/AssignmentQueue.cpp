#include "AssignmentQueue.hpp"
#include <fstream>

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
    // Create the file variable for writing using the file stored in "data" repository
    ofstream inData;
    inData.open("data/data.csv");

    // Load courses and assignments in the file respectively (using the following functions)
    saveCourseList(inData);
    saveAssignmentList(inData);

    // Close file when we're done with it
    inData.close();
}

void saveCourseList(ofstream& inData)
{
    for (Course& course : courses) {
        inData << course.courseName << ',' << course.currentGrade;
        for (Category& category : course.categories) {
            inData << ',' << category.name << ',' << category.value << ',' << category.numAssignments;
        }
        inData << '\n';
    }
}

void saveAssignmentList(ofstream& inData)
{
    priority_queue<Assignment> queue_copy = queue;
    inData << "Assignments:" << '\n';
    while (!queue_copy.empty()) {
        Assignment curr_assignment = queue_copy.popNext();
        inData << curr_assignment.assignmentName << ',' << curr_assignment.categoryName << ',' << curr_assignment.courseName << ',' << static_cast<int>((curr_assignment.dueDate).year()) << ',' << static_cast<unsigned>((curr_assignment.dueDate).month()) << ',' << static_cast<unsigned>((curr_assignment.dueDate).day()) << '\n';
    }
}

void load()
{
    // Create the file variable for reading using the file stored in "data" repository
    ifstream outData;
    outData.open("data/data.csv")

    // Load courses and assignments in the file respectively (using the following functions)
    loadCourseList(outData);
    loadAssignmentList(outData);

    // Close file when we're done with it
    outData.close();
}

void loadCourseList(ifstream& outData)
{
      
}

void loadAssignmentList(ifstream& outData)
{
      
}
