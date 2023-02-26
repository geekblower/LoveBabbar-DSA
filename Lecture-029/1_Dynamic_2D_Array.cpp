#include <bits/stdc++.h>
using namespace std;

int main() {
    int row, col;

    cout << "Enter the values of row & col : ";
    cin >> row >> col;

    // Creating a 2D Array Dynamically
    int **arr = new int *[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    // Taking input in a dynamically declared 2D Array
    cout << "Enter the elements of the array : " << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }

    // Printing a dynamically declared 2D Array
    cout << "Array elements : " << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    // Releasing Memory
    for(int i=0; i<row; i++) {
        delete []arr[i];
    }

    delete []arr;

    return 0;
}