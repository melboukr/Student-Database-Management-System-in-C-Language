#include <stdio.h>
#include "file_handler.h"

void saveToFile(LinkedList* list, const char* filename) {
    FILE* file = fopen(filename, "wb");

    if (file != NULL) {
        Node* current = list->head;
        while (current != NULL) {
            fwrite(&current->student, sizeof(Student), 1, file);
            current = current->next;
        }
        fclose(file);
        // printf("Data saved to file successfully.\n");
    } else {
        printf("Error: Unable to save data to file.\n");
    }
}

LinkedList* loadFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");

    if (file != NULL) {
        LinkedList* list = createLinkedList();
        Student student;
        while (fread(&student, sizeof(Student), 1, file) == 1) {
            insertNode(list, &student);
        }
        fclose(file);
        // printf("Data loaded from file successfully.\n");
        return list;
    } else {
        printf("Error: Unable to load data from file.\n");
        return NULL;
    }
}
