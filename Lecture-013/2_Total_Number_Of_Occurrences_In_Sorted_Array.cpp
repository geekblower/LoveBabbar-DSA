#include <iostream>
using namespace std;

int firstPosition(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

    int ans = -1;

    while(start <= end) {
        if(arr[mid] == key) {
            ans = mid;
            end = mid - 1;
        } else if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }

    return ans;
}

int lastPosition(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;

    int ans = -1;

    while(start <= end) {
        if(arr[mid] == key) {
            ans = mid;
            start = mid + 1;
        } else if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }

    return ans;
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

    cout<<"Enter the element to search for : ";
    cin>>element;
    
    int first = firstPosition(arr, n, element);
    int last = lastPosition(arr, n, element);
    int totOcc;

    if(first == -1 || last == -1) {
        totOcc = 0;
    } else {
        totOcc = last - first + 1;
    }

    cout<<"Total number of occurrences : "<<totOcc<<endl;

    return 0;
}