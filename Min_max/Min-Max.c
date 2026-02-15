#include <stdio.h>

int main() {
    int n; 

    //Print and scan the number of elemnets
    printf("Enter the number of elements: ");
    scanf("%d", &n);


    /*Handling the edgy case of the number of elements less than 0 or equal to zero because there will be no value for comparison*/
    if (n<=0){
        printf("Invalid Size\n"); //Removing the edgy case
        return 0;
    }

    int arr[n]; //Assigning an array


    /*
    Traversing: Accessing all the elements of an array.

    Example:
    Let’s consider a room as an array,
    and the chairs inside as the indices.
    If I want to find where a person 'X' is sitting,
    I have to check each chair one by one.

    This represents linear traversal.

    Technical Clarification:
    - Traversing means visiting every element sequentially from index 0 to n-1.
    - It is required when the array is unsorted.
    - Time Complexity of traversal is O(n).
    - Traversal is different from searching:
    Traversal = visiting all elements.
    Searching = looking for a specific element.
    - If the array is sorted, we can use Binary Search (O(log n)),
    otherwise we use Linear Search (O(n)).
    */

    printf("Enter the elements:");
    for (int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int min = arr[0];

    for (int i=1; i<n; i++ ){
        if(arr[i]>max)
        max = arr[i];

        if (arr[i]< min)
        min = arr[i];
    }

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}