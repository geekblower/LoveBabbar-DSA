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

void tripletSum(int arr[], int size, int sum) {
    for(int i=0; i<size-2; i++) {
        for(int j=i+1; j<size-1; j++) {

            for(int k=j+1; k<size; k++) {
                if(arr[i] + arr[j] + arr[k] == sum) {
                    cout<<"New triplet : "<<arr[i]<<", "<<arr[j]<<" & "<<arr[k]<<endl;
                }
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

    tripletSum(arr, size, targetSum);

    return 0;
}