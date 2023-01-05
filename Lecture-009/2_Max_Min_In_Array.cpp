#include <iostream>
#include <limits.h>
using namespace std;

int getMax(int arr[], int size) {
    int max = INT_MIN;

    for(int i=0; i<size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

int getMin(int arr[], int size) {
    int min = INT_MAX;

    for(int i=0; i<size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int main() {
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    int arr[100];

    cout<<"Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    cout<<"Maximum element of the array = "<<getMax(arr, size)<<endl;
    cout<<"Minimum element of the array = "<<getMin(arr, size)<<endl;

    return 0;
}