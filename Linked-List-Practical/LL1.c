#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

int main() {

    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));

    head->data = 100;
    second->data = 200;
    third->data = 300;

    head->next = second;
    second->next = third;
    third->next = NULL;

    Node* temp = head;
    while(temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    free(head);
    free(second);
    free(third);

    return 0;
}