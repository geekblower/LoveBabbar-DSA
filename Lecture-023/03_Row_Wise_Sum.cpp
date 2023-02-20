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

void printRowSum(int arr[][MAX], int row, int col) {
    for(int i=0; i<row; i++) {
        int sum = 0;
        for(int j=0; j<col; j++) {
            sum += arr[i][j];
        }
        cout << "Sum of row" << i+1 << " : " << sum << endl;
    }
}

int main() {
    int row, col;
    int arr[MAX][MAX];

    cout << "Enter the number of row & col : ";
    cin >> row >> col;
    
    cout << "Enter the elements of array : ";
    input2dArray(arr, row, col);

    printRowSum(arr, row, col);

    return 0;
}