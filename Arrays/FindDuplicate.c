#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {4, 5, 4, 2, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *temp = (int *)malloc(n * sizeof(int)); // Temporary array to store unique elements
    int count = 0; // Number of unique elements

    for (int i = 0; i < n; i++) {
        int is_duplicate = 0;
        // Check if the current element is already in the temp array
        for (int j = 0; j < count; j++) {
            if (arr[i] == temp[j]) {
                is_duplicate = 1;
                break;
            }
        }

        // If not a duplicate, add to temp and increment count
        if (!is_duplicate) {
            temp[count] = arr[i];
            count++;
        }
    }

    printf("Array after removing duplicates: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");

    return 0;
}
