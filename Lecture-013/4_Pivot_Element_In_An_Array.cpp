#include <iostream>
using namespace std;

int peakIndex(int arr[], int size) {
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

    int ans = -1;

    while(start < end) {
        if(arr[mid] < arr[mid+1]) {
            start = mid + 1;
        } else {
            end = mid;
        }

        mid = start + (end-start)/2;
    }

    return start;
}

int main() {
    int n, element;
    int arr[100];

    cout<<"Enter the size of the array : ";
    cin>>n;

    cout<<"Enter the elements of tha array : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int peak = peakIndex(arr, n);

    cout<<"Peak element of the array : "<<peak;

    return 0;
}

//1 3 5 15 18 20 30 25 25 24 22 21 19 16 14 13 10 9 9 1 