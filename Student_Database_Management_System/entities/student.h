#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    int age;
    float grade;
} Student;

#endif // STUDENT_H
