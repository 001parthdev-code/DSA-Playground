#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return; // Corrected: Just 'return' for void functions
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int main() {
    char str[MAX];
    printf("Enter the string: ");
    
    // Using %99s prevents the user from entering more than the array can hold
    scanf("%99s", str); 

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        push(str[i]);
    }

    for (int i = 0; i < n; i++) {
        str[i] = pop();
    }
    
    printf("Reversed string: %s\n", str);

    return 0;
}


