#include <bits/stdc++.h>
using namespace std;

int arraySum(int arr[], int size) {
    if(size == 1) {
        return arr[0];
    }

    return arr[0] + arraySum(arr+1, size-1);
}

int main() {
    int size;
    int arr[100];

    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    cout << "Sum of all elements : " << arraySum(arr, size) << endl;

    return 0;
}