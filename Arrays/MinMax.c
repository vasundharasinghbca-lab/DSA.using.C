#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;

    // If only one element
    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    // If two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    // More than two elements
    mid = (low + high) / 2;

    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);

    // Compare minimums
    result.min = (left.min < right.min) ? left.min : right.min;

    // Compare maximums
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 30000};
    int arr_size = 6;

    struct Pair minmax = getMinMax(arr, 0, arr_size - 1);

    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);

    return 0;
}
