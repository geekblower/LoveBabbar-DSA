#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int limit) {
    if(limit >= arr.size()) {
        return;
    }

    int j = limit-1;
    int temp = arr[limit];

    while(j >= 0) {
        if(arr[j] > temp) {
            arr[j+1] = arr[j];
        }
        j--;
    }

    arr[j+1] = temp;

    insertionSort(arr, limit+1);
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

    insertionSort(arr, 1);

    cout << "\nArray after sorting : ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
