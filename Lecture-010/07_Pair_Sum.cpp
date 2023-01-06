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

void pairSum(int arr[], int size, int sum) {
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if(arr[i] + arr[j] == sum) {
                cout<<"New pair : "<<arr[i]<<" & "<<arr[j]<<endl;
            }
        }
    }
}

int main() {
    int size, targetSum;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>size;

    cout<<"Enter the elements of array : ";
    inputArray(arr, size);

    cout<<"Enter the target sum : ";
    cin>>targetSum;

    pairSum(arr, size, targetSum);

    return 0;
}