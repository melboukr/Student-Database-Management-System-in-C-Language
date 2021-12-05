#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("Error: Memory allocation failed for LinkedList. Exiting...\n");
        return NULL;
    }
    list->head = NULL;
    return list;
}

int insertNode(LinkedList* list, const Student* student) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed for Node. Exiting...\n");
        return 0;
    }
    newNode->student = *student;
    newNode->next = list->head;
    list->head = newNode;
    return 1; // Success
}


void deleteNode(LinkedList* list, int rollNumber) {
    Node* current = list->head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->student.rollNumber == rollNumber) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            break;
        }

        prev = current;
        current = current->next;
    }
}

Node* findNode(LinkedList* list, int rollNumber) {
    Node* current = list->head;

    while (current != NULL) {
        if (current->student.rollNumber == rollNumber) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void displayLinkedList(LinkedList* list) {
    printf("==== All Students ====\n");
    Node* current = list->head;
    while (current != NULL) {
        printf("Name: %s, Roll Number: %d, Age: %d, Grade: %.2f\n",
               current->student.name, current->student.rollNumber, current->student.age, current->student.grade);
        current = current->next;
    }
}

void destroyLinkedList(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
