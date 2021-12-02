#include <stdio.h>
#include "student_service.h"

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

    printf("Enter Age: ");
    scanf("%d", &newStudent.age);
    printf("Enter Grade: ");
    scanf("%f", &newStudent.grade);

    insertNode(studentsList, &newStudent);
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
