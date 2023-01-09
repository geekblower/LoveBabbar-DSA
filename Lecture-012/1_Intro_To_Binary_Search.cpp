#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size-1;

    // int mid = (start+end)/2;

    // Formula to avoid overflowed values
    int mid = start + (end-start)/2;

    while(start <= end) {
        if(arr[mid] == key) {
            return mid;
        }

        if(key > arr[mid]) {
            // Go to right part
            start = mid + 1;
        } else {
            // Go to left part
            end = mid - 1;
        }

        mid = start + (end-start)/2;
    }

    return -1;
}

int main() {
    int evenSize[6] = {2, 4, 6, 8, 12, 18};
    int oddSize[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(evenSize, 6, 12);

    cout<<"Index of 12 is "<<evenIndex<<endl;

    int oddIndex = binarySearch(oddSize, 5, 3);

    cout<<"Index of 3 is "<<oddIndex<<endl;

    return 0;
}