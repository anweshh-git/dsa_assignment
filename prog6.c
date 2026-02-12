#include <stdio.h>
#define max 100

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//maxheap function
void maxheap( int n,int arr[], int i){
    int largest = i; //taking as parent
    int left = 2 * i + 1; //taking as left child
    int right = 2 * i + 2; //taking as right child

    if (left < n && arr[left] > arr[largest]){ //left becomes parent
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){ //right becomes parent
        largest = right;
    }

    if(largest != i){ //if any of the children are greater then swap with the parent
        swap(&arr[i], &arr[largest]);
        maxHeap(arr, n, largest);
    }

}
void buildmaxheap(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){ //to access the non leaf nodes
        maxheap( n,arr, i);
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
        minHeap(arr, n, smallest);
    }
}

//buildminheap function
void buildminheap( int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        minHeap(arr, n, i);
    }
}

