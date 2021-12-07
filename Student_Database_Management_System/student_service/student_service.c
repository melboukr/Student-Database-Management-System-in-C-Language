#include <stdio.h>
#include "student_service.h"
#include <stdbool.h>

static LinkedList* studentsList = NULL;
const char* studentDataFile = "data/studentDataFile.txt";

void initializeStudentService() {
    studentsList = loadFromFile(studentDataFile);
}

void cleanupStudentService() {
    destroyLinkedList(studentsList);
    studentsList = NULL;
}

void updateDataService() {
    saveToFile(studentsList, studentDataFile);
}

void displayAllStudentsService() {
    displayLinkedList(studentsList);
}

int integrityCheck(int rollNumber) {
    Node* current = studentsList->head;

    while (current != NULL) {
        if (current->student.rollNumber == rollNumber) {
            return 1; // Student with the given roll number found
        }
        current = current->next;
    }

    return 0; // Student with the given roll number not found
}

bool isValidAge(int age) {
    return (age >= 0 && age <= 120); // Assuming age is between 0 and 120
}

bool isValidGrade(float grade) {
    return (grade >= 0 && grade <= 100); // Assuming grade is between 0 and 100
}

void addStudentService() {
    Student newStudent;
    printf("Enter Student Name: ");
    scanf(" %[^\n]", newStudent.name);

    int rollNumber;
    do {
        printf("Enter Roll Number: ");
        scanf("%d", &rollNumber);

        if (integrityCheck(rollNumber)) {
            printf("A student with the same Roll Number already exists. Please try again.\n");
        }
    } while (integrityCheck(rollNumber));

    newStudent.rollNumber = rollNumber;

    int age;
    do {
        printf("Enter Age: ");
        scanf("%d", &age);

        if (!isValidAge(age)) {
            printf("Error: Invalid age. Please enter a valid age between 0 and 120.\n");
        }
    } while (!isValidAge(age));

    newStudent.age = age;

    float grade;
    do {
        printf("Enter Grade: ");
        scanf("%f", &grade);

        if (!isValidGrade(grade)) {
            printf("Error: Invalid grade. Please enter a valid grade between 0 and 100.\n");
        }
    } while (!isValidGrade(grade));

    newStudent.grade = grade;

    if (!insertNode(studentsList, &newStudent)) {
        printf("Error: Failed to add student. Memory allocation failed.\n");
        return;
    }
    updateDataService();
    printf("Student added successfully.\n");
}

void searchStudentService() {
    int rollNumber;
    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNumber);

    Node* result = findNode(studentsList, rollNumber);
    if (result != NULL) {
        printf("Student Found:\n");
        printf("Name: %s, Roll Number: %d, Age: %d, Grade: %.2f\n",
               result->student.name, result->student.rollNumber, result->student.age, result->student.grade);
    } else {
        printf("Student not found.\n");
    }
}

void updateStudentService() {
    int rollNumber;
    printf("Enter Roll Number to update: ");
    scanf("%d", &rollNumber);

    Node* result = findNode(studentsList, rollNumber);
    if (result != NULL) {
        printf("Enter new Grade: ");
        scanf("%f", &result->student.grade);
        printf("Student information updated.\n");
        updateDataService();
    } else {
        printf("Student not found.\n");
    }
}

void deleteStudentService() {
    int rollNumber;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &rollNumber);

    deleteNode(studentsList, rollNumber);
    updateDataService();

}
