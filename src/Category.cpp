Category(Course* currCourse, string inputName, double inputValue) : course(currCourse), catName(inputName), catValue(inputValue) {}

void addAssignment(string asName, int inputPoints, int dueYear, int dueMonth, int dueDay)
{
    assignments.push_back(new Assignment(asName, inputPoints, dueYear, dueMonth, dueDay));
}

void markAssignmentDone(string asName)
{
    for (Assignment& assignment : assignments) {
        if (assignment.assignmentName == asName) {
            assignment.is_done = true;
            break;
        }
    }
}
