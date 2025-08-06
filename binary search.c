#include <stdio.h>

void binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1, mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == key) {
            printf("Element %d found at index %d.\n", key, mid);
            return;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Element %d not found in the array.\n", key);
}
    int isSorted(int arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return 0;
            }
        }
        return 1;
    }
int main() {
    int n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (!isSorted(arr, n)) {
        printf("The array is not sorted in ascending order. Binary search cannot be performed.\n");
        return 1;
    }

    printf("Enter the element to search (key): ");
    scanf("%d", &key);

    binarySearch(arr, n, key);

    return 0;
}
