#include <iostream>
using namespace std;

int pivotIndex(int arr[], int size) {
    int start = 0;
    int end = size-1;

    while(start < end) {
        int mid = start + (end-start)/2;

        if(arr[mid] > arr[size-1]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return start;
}

int main() {
    int n;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>n;

    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int pivot = pivotIndex(arr, n);

    cout<<"Pivot element = "<<arr[pivot]<<endl;

    return 0;
}
