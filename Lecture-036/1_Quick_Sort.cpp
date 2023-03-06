#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[start];
    int lessCount = 0;

    for(int i=start+1; i<=end; i++) {
        if(arr[i] <= pivot) {
            lessCount++;
        }
    }

    int pivotIndex = start + lessCount;
    swap(arr[start], arr[pivotIndex]);

    int i = start;
    int j = end;

    while(i<pivotIndex && j>pivotIndex) {
        while(arr[i] <= pivot) {
            i++;
        }

        while(arr[j] > pivot) {
            j--;
        }

        if(i<pivotIndex && j>pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    } 

    return pivotIndex;
}

void quickSort(vector<int> &arr, int start, int end) {
    if(start >= end) {
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
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

    quickSort(arr, 0, size-1);

    cout << endl << "After sorting : ";
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}