#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr, int start) {
    if(start >= arr.size()-1) {
        return;
    }

    int minIndex = start;
    
    for(int i=start; i<arr.size(); i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    swap(arr[start], arr[minIndex]);

    selectionSort(arr, start+1);
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

    selectionSort(arr, 0);

    cout << "\nArray after sorting : ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
