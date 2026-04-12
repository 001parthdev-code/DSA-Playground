#include <stdio.h>
#include <stdlib.h> // Necessary for malloc

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Helper to create a new node
Node* createNewNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Helper to insert at the end of the list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = createNewNode(value);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Your logic - Corrected!
Node* deleteDuplicatevalues(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            Node* toDelete = temp->next; // Good practice: save it to free later
            temp->next = temp->next->next;
            free(toDelete); // Clean up memory
        } else {
            temp = temp->next;
        }
    }
    return head;
}

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
    int n,value,k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        head = insertAtEnd(head, value);
    }

    printf("Original List: ");
    traverse(head);

    head = deleteDuplicatevalues(head);

    printf("After Removing Duplicates: ");
    traverse(head);

    // Freeing memory for the remaining nodes
    while (head != NULL) {
        Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}