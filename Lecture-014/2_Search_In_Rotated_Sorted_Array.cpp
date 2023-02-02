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

int searchElement(int arr[], int start, int end, int target) {
    while(start <= end) {
        int mid = start + (end-start)/2;

        if(arr[mid] == target) {
            return mid;
        } else if(arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n, key;
    int arr[100];

    cout<<"Enter the size of array : ";
    cin>>n;

    cout<<"Enter the elements of the array : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the element to search for : ";
    cin>>key;

    int pivot = pivotIndex(arr, n);
    int index;

    if(key > arr[n-1]) {
        index = searchElement(arr, 0, pivot-1, key);
    } else {
        index = searchElement(arr, pivot, n-1, key);
    }

    if(index == -1) {
        cout<<"Element not found in the array!"<<endl;
    } else {
        cout<<"Element found in the array at index : "<<index<<endl;
    }

    return 0;
}
