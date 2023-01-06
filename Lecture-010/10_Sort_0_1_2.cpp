#include <iostream>
using namespace std;

void inputArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
}

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// DNF (Dutch-National-Flag) Algorithm
// Red - White - Blue Ball Questions
// low - mid - high variables (3 pointers)
void sort012(int arr[], int size) {
    int low = 0;
    int mid = 0;
    int high = size-1;

    while(mid <= high) {
 
        switch(arr[mid]) {
            case 0:
                swap(arr[mid++], arr[low++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high--]);
                break;
        }
        
    }
}

int main() {
    int size;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    inputArray(arr, size);

    cout<<"Array before sorting : ";
    printArray(arr, size);

    sort012(arr, size);

    cout<<"Array after sorting : ";
    printArray(arr, size);

    return 0;
}