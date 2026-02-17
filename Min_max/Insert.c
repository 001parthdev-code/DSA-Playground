#include <stdio.h>

int main() {
    int n, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];   // fixed capacity for insertion

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position (1-based): ");
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return 0;
    }

    for (int i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = value;
    n++;

    printf("Updated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
