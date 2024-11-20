#include <stdio.h>

void selectionSort(int arr[], int n, int index) {
    if (index == n - 1) return; // Base case

    int minIdx = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
    }

    // Swap the minimum element with the current index
    int temp = arr[minIdx];
    arr[minIdx] = arr[index];
    arr[index] = temp;

    // Recursive call for the remaining array
    selectionSort(arr, n, index + 1);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n, 0);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
