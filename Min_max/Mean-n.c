#include <stdio.h>

int main() {
    int n;
    double sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return 0;
    }

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    double mean = sum / n;

    printf("Mean = %.2lf\n", mean);

    return 0;
}
