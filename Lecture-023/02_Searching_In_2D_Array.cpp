#include <bits/stdc++.h>
using namespace std;
#define MAX 100

void input2dArray(int arr[][MAX], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }
}

bool isPresent(int arr[][MAX], int row, int col, int target) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {

            if(arr[i][j] == target) {
                return true;
            }
        
        }
    }

    return false;
}

int main() {
    int row, col, target;
    int arr[MAX][MAX];

    cout << "Enter the number of row & col : ";
    cin >> row >> col;
    
    cout << "Enter the elements of array : ";
    input2dArray(arr, row, col);

    cout << "Enter the target : ";
    cin >> target;

    if(isPresent(arr, row, col, target)) {
        cout << "Element is present!" << endl;
    } else {
        cout << "Element is not present!" << endl;
    }

    return 0;
}