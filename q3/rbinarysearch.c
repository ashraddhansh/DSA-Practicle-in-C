#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;  // Element not found
    }

    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;  // Element found at mid
    } 
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);  // Search in left half
    }
    return binarySearch(arr, mid + 1, right, target);  // Search in right half
}

int main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, size - 1, target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
