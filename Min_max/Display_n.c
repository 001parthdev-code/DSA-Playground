#include <stdio.h>

int main() {
    int n;

    // Take number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0) {
        printf("Invalid size\n");
        return 0;
    }

    int arr[n];   // Declare array of size n

    // Read elements
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display elements
    printf("The elements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
