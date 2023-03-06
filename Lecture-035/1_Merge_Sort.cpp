#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int> &arr, int start, int end) {
    int mid = start + (end-start)/2;

    vector<int> arr1(mid-start+1);
    vector<int> arr2(end-mid);

    for(int i=start, j=0; j<arr1.size(); i++, j++) {
        arr1[j] = arr[i];
    }

    for(int i=mid+1, j=0; j<arr2.size(); i++, j++) {
        arr2[j] = arr[i];
    }

    int i=0, j=0, index=start;

    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] < arr2[j]) {
            arr[index++] = arr1[i++];
        } else {
            arr[index++] = arr2[j++];
        }
    }

    while(i<arr1.size()) {
        arr[index++] = arr1[i++];
    }

    while(j<arr2.size()) {
        arr[index++] = arr2[j++];
    }
}

void mergeSort(vector<int> &arr, int start, int end) {
    if(start >= end) {
        return;
    }
    
    int mid = start + (end-start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    mergeArrays(arr, start, end);
}

int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of the array : ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    cout << endl << "Before sorting : ";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, size-1);

    cout << endl << "After sorting : ";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}