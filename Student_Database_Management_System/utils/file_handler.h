#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "linked_list.h"

// Save student records to a file
void saveToFile(LinkedList* list, const char* filename);

// Load student records from a file
LinkedList* loadFromFile(const char* filename);

#endif // FILE_HANDLER_H
