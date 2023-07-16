#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
            
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int size) {
    while(size > 1) {
        swap(arr[1], arr[size]);

        size--;
        
        heapify(arr, size, 1);
    }
}

int main() {
    int arr[6] = {-1, 54, 53, 55, 50, 52};
    int size = 5;
    
    // Heap creation
    for(int i = size/2; i>0; i--) {
        heapify(arr, size, i);
    }
    
    cout << "UnSorted array : ";
    for(int i=1; i<=size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Calling heap sort
    heapSort(arr, size);

    cout << "Sorted array (Heap Sort) : ";
    for(int i=1; i<=size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}