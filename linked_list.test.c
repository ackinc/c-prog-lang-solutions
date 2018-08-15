#include <stdlib.h>

#include "linked_list.h"

void main() {
    ListElement *list = (ListElement *)malloc(sizeof(ListElement));

    createList(&list);
    printList(list); // empty

    insertInFront(&list, 1);
    insertInFront(&list, 2);
    insertInFront(&list, 3);
    insertInFront(&list, 4);
    insertInFront(&list, 5);
    printList(list); // 5, 4, 3, 2, 1

    ListElement *e = findElem(list, 6);
    if (!e) e = findElem(list, 2);

    deleteElem(&list, e);
    printList(list); // 5, 4, 3, 1

    e = findElem(list, 4);
    insertAfter(&list, e, 6);
    printList(list); // 5, 4, 6, 3, 1

    deleteList(&list);
    printList(list); // empty
}
