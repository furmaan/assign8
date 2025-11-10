#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int heap[MAX];
int size = 0;

/* ----------------------------------------------------------
   Function to swap two elements
   ---------------------------------------------------------- */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ----------------------------------------------------------
   Function to insert a new element into the heap (MAX-HEAP)
   ---------------------------------------------------------- */
void insert(int value) {
    if (size >= MAX) {
        printf("Priority Queue is full!\n");
        return;
    }

    size++;
    int i = size - 1;
    heap[i] = value;

    // Fix the max heap property
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    printf("Inserted %d into the priority queue.\n", value);
}

/* ----------------------------------------------------------
   Function to heapify a subtree (for deletion)
   ---------------------------------------------------------- */
void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapify(largest);
    }
}

/* ----------------------------------------------------------
   Function to extract (delete) the maximum element
   ---------------------------------------------------------- */
int extractMax() {
    if (size <= 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapify(0);

    return root;
}

/* ----------------------------------------------------------
   Function to display the priority queue
   ---------------------------------------------------------- */
void display() {
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue (Heap Array): ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

/* ----------------------------------------------------------
   MAIN FUNCTION
   ---------------------------------------------------------- */
int main() {
    int choice, value;

    while (1) {
        printf("\n---- Priority Queue using Heap ----\n");
        printf("1. Insert\n");
        printf("2. Extract Maximum\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            value = extractMax();
            if (value != -1)
                printf("Extracted max element: %d\n", value);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
