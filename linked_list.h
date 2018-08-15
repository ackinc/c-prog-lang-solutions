#include <stdbool.h>

typedef struct ListElement {
    struct ListElement *next;
    int data;
} ListElement;

bool createList(ListElement **head);
bool deleteList(ListElement **head);
ListElement *findElem(ListElement *head, int data);
bool deleteElem(ListElement **head, ListElement *toDelete);
bool insertInFront(ListElement **head, int data);
bool insertAfter(ListElement **head, ListElement *node, int data);
void printList(ListElement *head);
