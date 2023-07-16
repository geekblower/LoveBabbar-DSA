#include <bits/stdc++.h>
using namespace std;

/*
    0 based indexing
    left - 2*i + 1;
    right - 2*i + 2;    
*/

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    

    if(left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
            
    if(right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int>& arr) {
    int n = arr.size();

    for(int i=(n/2)-1; i>=0; i--) {
        heapify(arr, n, i);
    }

    return arr;
}

int  main() {
    vector<int> arr = {90, 30, 20, 120, 50, 60, 40, 150};

    // Heapifing array
    cout << "Before building Min Heap : ";
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = buildMinHeap(arr);
    
    cout << "After building Min Heap : ";
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
