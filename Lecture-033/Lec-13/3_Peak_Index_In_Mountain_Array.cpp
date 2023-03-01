#include <iostream>
using namespace std;

int peakIndex(int arr[], int start, int end) {
    if(start >= end) {
        return -1;
    }

    int mid = start + (end-start)/2;

    if(arr[mid] >= arr[mid+1]) {
        int temp = peakIndex(arr, start, mid);
        return (temp == -1) ? mid : temp;
    } else {
        return peakIndex(arr, mid+1, end);
    }
}

int main() {
    int n, element;
    int arr[100];

    cout << "Enter the size of the array : ";
    cin >> n;

    cout << "Enter the elements of tha array : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int peak = peakIndex(arr, 0, n-1);

    cout << "Peak element of the array : " << arr[peak];

    return 0;
}