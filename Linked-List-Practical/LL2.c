#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void printList(Node* head){
    while (head){
        printf("%d ->",  head-> data);
        head = head-> next;
    }
    printf("NULL\n");

}

int main() {

    Node* head = NULL;

    head = malloc(sizeof(Node));
    head-> data = 10;
    head->next = malloc(sizeof(Node));
    head->next-> data = 20;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    head = reverseList(head);
    printList(head);
    
    return 0;
}