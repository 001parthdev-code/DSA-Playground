/*
Next Problem — Delete Last Node

Problem Statement

Delete the last node from a singly linked list.

Example:

10 → 20 → 30 → 40 → NULL

After deletion:

10 → 20 → 30 → NULL
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Creates a new node in memory
Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) return NULL; 
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Adds a node to the end of the list so we have data to work with
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// The core logic: Deleting the last node
Node* DeleteAtEnd(Node* head) {
    // Case 1: List is empty
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    // Case 2: List has only one node
    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    // Case 3: List has 2 or more nodes
    Node* temp = head;
    // We stop at the second-to-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // temp is now the second-to-last node. 
    // temp->next is the node we want to remove.
    free(temp->next);
    
    // Crucial: Set the new end of the list to NULL
    temp->next = NULL;

    return head;
}

// Prints the list to the console
void traverse(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, value;

    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    printf("\nOriginal List:\n");
    traverse(head);

    if (n > 0) {
        printf("\nDeleting the last node...\n");
        head = DeleteAtEnd(head);
        
        printf("Updated List:\n");
        traverse(head);
    }

    return 0;
}