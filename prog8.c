#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//long long  is used for safe enviornment because the comparision and swaps can get very big
long long swaps = 0; //stores the number of swap
long long comparisons = 0; //stores the number of comparisons

//function to print the array
void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


//bubble sort implementation
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapscount++;
            }
        }
    }
}

//selection sort implementation
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
}
//insertion sort implementation
void insertion_sort(int arr[], int n) {
    comparisons = swaps = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        comparisons++;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            swaps++;
            j--;
        }
        arr[j + 1] = key;
    }
}
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {
    int n, choice;

    printf("enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
//random numbers between 1 and 1000 are generated and stored in the array
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000 + 1;

    printf("\nNumbers before sorting:\n");
    print(arr, n);

    printf("\nChoose Sorting Algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("enter your choice: ");
    scanf("%d", &choice);
    comparisons = 0;
    swaps = 0;
    //switch case implemnetation for sorting
     switch (choice) {
        case 1:
            bubble_sort(arr, n);
            break;
        case 2:
            selection_sort(arr, n);
            break;
        case 3:
            insertion_sort(arr, n);
            break;
        case 4:
            merge_sort(arr, 0, n- 1);
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    printf("\nNumbers after sorting:\n");
    print(arr, n);

    printf("\nPerformance metrics:\n");
    printf("Total Comparisons: %lld\n", comparisons);

    if (choice != 4) // merge sort doesnt swap so its not applicable with swapscount
        printf("Total Swaps: %lld\n", swapsCount);
    else
        printf("Swaps: Not applicable for Merge Sort\n");

    return 0;
}

