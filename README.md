# Assignment-Checklist
C++ assignment tracker for a student that prioritizes coursework based on due date, point values, and current course grade. 


## Structural Overview
This project uses a priority queue of specially weighted assignment objects to find the best order to do assignments in.

Each assignment stores the key for the course that it is in.

Each course stores the data required to prioritize its assignments, such as the current grade, and how much a certain type of assignment is worth.


## Use
### Adding Courses
To use the assignment tracker, we first need to add our courses and set their parameters

Select add course, and enter the name for the new course.
Then, set the categories of assignments and their worth. The categories must add up to 100%
Add all of your courses.

### Adding Assignments
Now that you have added courses to the checklist, you can add your assignments.

Select add assignment.
Set the course for which it is assigned, and the name of the assignment.
Then, select the category.
Add your upcoming assignments.

### Viewing the Checklist
To view the checklist, select view checklist

