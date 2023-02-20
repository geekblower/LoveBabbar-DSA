#include <bits/stdc++.h>
using namespace std;

int main() {


    // Create 2D-Array
    int arr[3][4];

    // Taking Input row wise
    cout << "Enter the elements : ";
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cin >> arr[row][col];
        }
    }

    // Printing 2D-Array
    cout << "Row-wise Elements : \n";
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    // Taking Input column wise
    cout << "\nEnter the elements : ";
    for(int col=0; col<4; col++) {
        for(int row=0; row<3; row++) {
            cin >> arr[row][col];
        }
    }

    // Printing 2D-Array
    cout << "Column-wise Elements : \n";
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << "arr1 Elements : \n";
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cout << arr1[row][col] << " ";
        }
        cout << endl;
    }

    int arr2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << "arr2 Elements : \n";
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cout << arr2[row][col] << " ";
        }
        cout << endl;
    }

    int arr3[3][4] = {0};
    cout << "arr3 Elements : \n";
    for(int row=0; row<3; row++) {
        for(int col=0; col<4; col++) {
            cout << arr3[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}