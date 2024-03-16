#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertAtBeginning(struct Node** headRef, int newData) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }


    newNode->data = newData;
    newNode->next = *headRef;


    *headRef = newNode;
}


void deleteNode(struct Node** headRef, int key) {

    if (*headRef == NULL) {
        printf("List is empty. Cannot perform deletion.\n");
        return;
    }


    if ((*headRef)->data == key) {
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }


    struct Node* prev = *headRef;
    while (prev->next != NULL && prev->next->data != key) {
        prev = prev->next;
    }


    if (prev->next == NULL) {
        printf("Key not found in the list. Cannot perform deletion.\n");
        return;
    }


    struct Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}


void printList(struct Node* node) {
    printf("Linked list: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


void freeList(struct Node** headRef) {
    struct Node* current = *headRef;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *headRef = NULL;
}

int main() {

    struct Node* head = NULL;


    insertAtBeginning(&head,5 );
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);


    printList(head);


    deleteNode(&head, 10);
    printf("After deleting 10: ");
    printList(head);


    freeList(&head);

    return 0;
}
