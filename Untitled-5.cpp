#include <stdio.h>

// Function to heapify a subtree rooted with node i
void heapify(int arr[], int n, int i, int order) {
    int extreme = i; // largest (for increasing) or smallest (for decreasing)
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // For increasing order → build max heap
    // For decreasing order → build min heap
    if (order == 1) { // Increasing order
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else { // Decreasing order
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    // If root is not extreme, swap and continue heapifying
    if (extreme != i) {
        int temp = arr[i];
        arr[i] = arr[extreme];
        arr[extreme] = temp;
        heapify(arr, n, extreme, order);
    }
}

// Function to perform Heapsort
void heapSort(int arr[], int n, int order) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, order);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify reduced heap
        heapify(arr, i, 0, order);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int arr[50], n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nChoose Sorting Order:\n");
    printf("1. Increasing Order\n");
    printf("2. Decreasing Order\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        heapSort(arr, n, 1);
    else
        heapSort(arr, n, 2);

    printf("\nSorted Array: ");
    printArray(arr, n);

    return 0;
}
