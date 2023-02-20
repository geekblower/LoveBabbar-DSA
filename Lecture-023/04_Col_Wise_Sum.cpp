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

void printColSum(int arr[][MAX], int row, int col) {
    for(int i=0; i<col; i++) {
        int sum = 0;
        for(int j=0; j<row; j++) {
            sum += arr[j][i];
        }
        cout << "Sum of col" << i+1 << " : " << sum << endl;
    }
}

int main() {
    int row, col;
    int arr[MAX][MAX];

    cout << "Enter the number of row & col : ";
    cin >> row >> col;
    
    cout << "Enter the elements of array : ";
    input2dArray(arr, row, col);

    printColSum(arr, row, col);

    return 0;
}