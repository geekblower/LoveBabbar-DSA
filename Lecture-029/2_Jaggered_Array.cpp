#include <bits/stdc++.h>
using namespace std;

int main() {
    int row;

    cout << "Enter the value of row : ";
    cin >> row;

    int **arr = new int *[row];

    for(int i=0; i<row; i++) {
        int col;
        cout << "Enter col : ";
        cin >> col;

        arr[i] = new int[col+1];

        for(int j=0; j<col; j++) {
            cin >> arr[i][j];
        }

        arr[i][col] = INT_MIN;
    }

    cout << "Array elements : " << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; arr[i][j] != INT_MIN; j++) {
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