#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int findUnique(int arr[], int size) {
    int unique = 0;

    for(int i=0; i<size; i++) {
        unique = unique ^ arr[i];
    }
    
    return unique;
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

    cout<<"Single unique element present in the array : "<<findUnique(arr, size)<<endl;

    return 0;
}