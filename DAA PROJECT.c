#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            printArray(arr, n);
            sleep(1);
        }
        printf("After pass %d: ", i + 1);
        printArray(arr, n);
        sleep(1);
    }
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            printArray(arr, n);
            sleep(1);
        }
        arr[j + 1] = key;
        printf("After inserting element %d: ", i);
        printArray(arr, n);
        sleep(1);
    }
}
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;

        printf("After pass %d: ", i + 1);
        printArray(arr, n);
        sleep(1);
    }
}
int main() {
    int choice, n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("\nSorting Visualization:\n");

    switch (choice) {
        case 1: bubbleSort(arr, n); break;
        case 2: insertionSort(arr, n); break;
        case 3: selectionSort(arr, n); break;
        default: printf("Invalid choice!\n");
    }

    printf("\nFinal Sorted Array: ");
    printArray(arr, n);
    return 0;
}
