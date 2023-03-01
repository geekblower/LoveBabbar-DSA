#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int size, int key) {
    if(size == 0) {
        return false;
    }

    if(arr[0] == key) {
        return true;
    } else {
        return linearSearch(arr+1, size-1, key);
    }
}

int main() {
    int size, key;
    int arr[100];

    cout << "Enter the size : ";
    cin >> size;

    cout << "Enter the elements of array : ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    cout << "Enter th element to search for : ";
    cin >> key;

    if(linearSearch(arr, size, key)) {
        cout << "Element is present !" << endl;
    } else {
        cout << "Element is not present !" << endl;
    }

    return 0;
}