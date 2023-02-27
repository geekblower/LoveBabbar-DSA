#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size, int start = 0) {
    for(int i = start; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[5] = {4, 6, 2, 6, 9};

    cout << "Array from index 1 : ";
    printArray(arr, 5, 1);

    cout << "Whole array : ";
    printArray(arr, 5);

    return 0;
}