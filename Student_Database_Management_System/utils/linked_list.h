#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../entities/student.h"

typedef struct Node {
    Student student;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

LinkedList* createLinkedList();
int insertNode(LinkedList* list, const Student* student);
void deleteNode(LinkedList* list, int rollNumber);
Node* findNode(LinkedList* list, int rollNumber);
void displayLinkedList(LinkedList* list);
void destroyLinkedList(LinkedList* list);

#endif // LINKED_LIST_H
