//Implement binary search on a sorted array. The bug lies in the mid calculation, where operator precedence leads to an incorrect index.
 //Code:

#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        // Bug: Due to operator precedence, mid is computed as low + (high / 2) rather than low + ((high - low) / 2).
        int mid = low + high / 2;  
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int index = binarySearch(arr, size, target);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");
    return 0;
}

// Output:

Element found at index 3

