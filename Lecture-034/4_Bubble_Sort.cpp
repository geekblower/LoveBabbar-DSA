#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int size) {
    if(size <= 1) {
        return;
    }

    for(int i=0; i<size-1; i++) {
        if(arr[i] > arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }

    bubbleSort(arr, size-1);
}

int main() {
    int n;

    cout << "Enter the size of array : ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements of array : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before sorting : ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    bubbleSort(arr, n);

    cout << "\nArray after sorting : ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
