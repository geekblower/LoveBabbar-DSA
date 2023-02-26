#include <bits/stdc++.h>
using namespace std;

int getSum(int arr[], int n) {
    int sum = 0;

    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    
    return sum;
}

int main() {
    int n;

    cout << "Enter the value of n : ";
    cin >> n;

    // Dynamic allocation of an array
    int *arr = new int[n];

    cout << "Enter the elements of array : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Sum of all elements : " << getSum(arr, n) << endl;

    delete []arr;

    return 0;
}