#include <stdio.h>
#include "student_service/student_service.h"

int main() {
    int choice;
    initializeStudentService();

    do {
        printf("==== Student Database Management ====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentService();
                break;
            case 2:
                displayAllStudentsService();
                break;
            case 3:
                searchStudentService();
                break;
            case 4:
                updateStudentService();
                break;
            case 5:
                deleteStudentService();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    cleanupStudentService();
    return 0;
}
