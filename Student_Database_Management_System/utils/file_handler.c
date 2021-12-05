#include <stdio.h>
#include "file_handler.h"

void saveToFile(LinkedList* list, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        if (fwrite(&current->student, sizeof(Student), 1, file) != 1) {
            printf("Error: Failed to write student data to file.\n");
            fclose(file);
            return;
        }
        current = current->next;
    }
    fclose(file);
    printf("Data saved to file successfully.\n");
}

LinkedList* loadFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file for reading.\n");
        return NULL;
    }
    LinkedList* list = createLinkedList();
    if (list == NULL) {
        fclose(file);
        return NULL;
    }
    Student student;
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (insertNode(list, &student) == 0) {
            printf("Error: Failed to load student data into memory.\n");
            fclose(file);
            destroyLinkedList(list);
            return NULL;
        }
    }
    fclose(file);
    printf("Data loaded from file successfully.\n");
    return list;
}
