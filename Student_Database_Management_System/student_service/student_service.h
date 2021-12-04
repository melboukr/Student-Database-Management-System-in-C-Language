#ifndef STUDENT_SERVICE_H
#define STUDENT_SERVICE_H

#include "../utils/linked_list.h"
#include "../utils/file_handler.h"

// Initialize the Student service
void initializeStudentService();

// Cleanup resources used by the Student service
void cleanupStudentService();

// Add a new student to the database
void addStudentService();

// Display all students in the database
void displayAllStudentsService();

// Search for a student by roll number
void searchStudentService();

// Update student information
void updateStudentService();

// Delete a student from the database
void deleteStudentService();

// update database
void updateDataService();

#endif // STUDENT_SERVICE_H
