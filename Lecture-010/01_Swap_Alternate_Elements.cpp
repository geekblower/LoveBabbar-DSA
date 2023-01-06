#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr[], int size) {
    for(int i=0; i<size-1; i+=2) {
        swap(arr[i], arr[i+1]);
    }
}

int main() {
    int size;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    cout<<"Before swaping alternate elements : ";
    printArray(arr, size);

    swapAlternate(arr, size);
    
    cout<<"After swaping alternate elements : ";
    printArray(arr, size);

    return 0;
}