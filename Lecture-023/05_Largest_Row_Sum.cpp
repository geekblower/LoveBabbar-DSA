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

int largestRowSum(int arr[][MAX], int row, int col) {
    int maxSum = INT_MIN;

    for(int i=0; i<row; i++) {
        int sum = 0;
        for(int j=0; j<col; j++) {
            sum += arr[i][j];
        }
        
        if(sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}

int main() {
    int row, col;
    int arr[MAX][MAX];

    cout << "Enter the number of row & col : ";
    cin >> row >> col;
    
    cout << "Enter the elements of array : ";
    input2dArray(arr, row, col);

    cout << "Largest row sum : " << largestRowSum(arr, row, col) << endl;

    return 0;
}