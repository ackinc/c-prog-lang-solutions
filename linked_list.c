/*
    Singly-linked list that supports the following operations:
        createList
        deleteList
        findElem
        deleteElem
        insertInFront
        insertAfter
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

bool createList(ListElement **head) {
    *head = NULL;
    return true;
}

bool deleteList(ListElement **head) {
    if (!head) return false;

    ListElement *next;
    while (*head) {
        next = (*head)->next;
        free(*head);
        *head = next;
    }
    return true;
}

ListElement *findElem(ListElement *head, int data) {
    while (head) {
        if (head->data == data) return head;
        head = head->next;
    }
    return NULL;
}

bool deleteElem(ListElement **head, ListElement *toDelete) {
    if (!head || !*head || !toDelete) return false;

    if (*head == toDelete) {
        *head = toDelete->next;
        free(toDelete);
        return true;
    }

    ListElement *cur = *head;
    while (cur->next) {
        if (cur->next == toDelete) {
            cur->next = toDelete->next;
            free(toDelete);
            return true;
        }
        cur = cur->next;
    }
    return false; // could not find toDelete in list
}

bool insertInFront(ListElement **head, int data) {
    ListElement *newElem = (ListElement *)malloc(sizeof(ListElement));
    if (!newElem) return false;

    newElem->data = data;
    newElem->next = *head;
    *head = newElem;
    return true;
}

bool insertAfter(ListElement **head, ListElement *node, int data) {
    ListElement *newElem = (ListElement *)malloc(sizeof(ListElement));
    if (!newElem) return false;

    newElem->data = data;
    if (node == NULL) { // insert at front of list
        newElem->next = *head;
        *head = newElem;
    } else {
        newElem->next = node->next;
        node->next = newElem;
    }
    return true;
}

void printList(ListElement *head) {
    printf("List: ");
    while (head) {
        printf("%d", head->data);
        if (head = head->next) printf(", ");
    }
    printf("\n");
}
