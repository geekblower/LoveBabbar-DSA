#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key) {
    if(start > end) {
        return false;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] == key) {
        return true;
    } else if(arr[mid] > key) {
        return binarySearch(arr, start, mid-1, key);
    } else {
        return binarySearch(arr, mid+1, end, key);
    }
}

int main() {
    int size, key;
    int arr[100];

    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    cout << "Enter th element to search for : ";
    cin >> key;

    if(binarySearch(arr, 0, size-1, key)) {
        cout << "Element is present !" << endl;
    } else {
        cout << "Element is not present !" << endl;
    }

    return 0;
}