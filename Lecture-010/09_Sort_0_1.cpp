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

void sort01(int arr[], int size) {
    int start = 0;
    int end = size-1;

    while(start <= end) {
        while(arr[start] == 0 && start <= end) {
            start++;
        }

        while(arr[end] == 1 && start <= end) {
            end--;
        }

        while(arr[start]==1 && arr[end]==0 && start <= end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
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

    sort01(arr, size);

    cout<<"Array after sorting : ";
    printArray(arr, size);

    return 0;
}