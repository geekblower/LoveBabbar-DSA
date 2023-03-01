#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size) {
    if(size == 1) {
        return true;
    }

    if(arr[size-1] < arr[size-2]) {
        return false;
    } else {
        return isSorted(arr, size-1);
    }
}

/*
bool isSorted(int arr[], int size) {
    if(size == 0 || size == 1) {
        return true;
    }

    if(arr[0] > arr[1]) {
        return false;
    } else {
        return isSorted(arr+1, size-1);
    }
}
*/

int main() {
    int size;
    int arr[100];

    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    if(isSorted(arr, size)) {
        cout << "Array is sorted !" << endl;
    } else {
        cout << "Array is not sorted !" << endl;
    }

    return 0;
}