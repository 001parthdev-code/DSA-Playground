#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return 0;
    }

    int arr[n];
    int found = 0;

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                found = 1;
                break;
            }
        }
        if (found) break;
    }

    if (found)
        printf("Duplicate exists\n");
    else
        printf("No duplicate found\n");

    return 0;
}
