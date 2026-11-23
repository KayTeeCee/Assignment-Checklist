Category(Course* currCourse, string inputName, double inputValue, int inputNumAssignments) : course(currCourse), catName(inputName), catValue(inputValue), catNumAssignments(inputNumAssignments) {}

void addAssignment(string asName, int dueYear, int dueMonth, int dueDay)
{
    assignments.push_back(new Assignment(asName, dueYear, dueMonth, dueDay));
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
