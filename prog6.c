#include <stdio.h>
#define max 100

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//maxheap function
void maxheap( int arr[],int n, int i){
    int largest = i; //taking as parent
    int left = 2 * i + 1; //taking as left child
    int right = 2 * i + 2; //taking as right child

    if (left < n && arr[left] > arr[largest]){ //left becomes parent
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){ //right becomes parent
        largest = right;
    }

    if(largest != i){     //if any child > parent then swap
        swap(&arr[i], &arr[largest]);
        maxHeap(arr, n, largest);
    }

}
void buildmaxheap(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){ //to access the non leaf nodes
        maxheap(arr , n , largest);
    }
}

//minheap function(smallest element becomes parent)
void minheap(int arr[], int n, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }

    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != i){
        swap(&arr[i], &arr[smallest]);
        minheap(arr, n, smallest);
    }
}

//buildminheap function
void buildminheap( int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        minHeap(arr, n, i);
    }
}
//main function
int main() {
    int arr[] = {12,4,6,1,8,10,18};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("before building heap:");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

//building max heap
    buildmaxheap(arr, n);
    printf("max heap: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
//building min heap
    int arr2[] = {12,4,6,1,8,10,18};
    buildminheap(arr2, n);
    printf("min Heap: ");

    for (int i = 0; i < n; i++){
        printf("%d ", arr2[i]);
    }

    return 0;
}