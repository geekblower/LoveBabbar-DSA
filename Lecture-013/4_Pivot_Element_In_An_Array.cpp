#include <iostream>
using namespace std;

int pivotElement(int arr[], int size) {
    int sum[100] = {0};

    for(int i=0; i<size; i++) {
        sum[i+1] = sum[i] + arr[i];
    }

    for(int i=0; i<size; i++) {
        int left = sum[i];
        int right = sum[size] - sum[i+1];

        if(left == right) {
            return arr[i];
        }
    }

    return -1;
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

    int pivot = pivotElement(arr, n);

    cout<<"Pivot element of the array : "<<pivot;

    return 0;
}
