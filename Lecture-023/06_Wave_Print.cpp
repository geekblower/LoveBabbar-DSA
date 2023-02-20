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

vector<int> wavePrint(int arr[][MAX], int row, int col) {
    vector<int> wave;
    
    for(int i=0; i<col; i++) {
        if(i&1) {
            for(int j=row-1; j>=0; j--) {
                wave.push_back(arr[j][i]);
            }
        } else {
            for(int j=0; j<row; j++) {
                wave.push_back(arr[j][i]);
            }
        }
    }

    return wave;
}

int main() {
    int row, col;
    int arr[MAX][MAX];

    cout << "Enter the number of row & col : ";
    cin >> row >> col;
    
    cout << "Enter the elements of array : \n";
    input2dArray(arr, row, col);

    vector<int> wave = wavePrint(arr, row, col);

    cout << "Wave print of array : ";
    for(int i:wave) {
        cout << i << " ";
    }

    return 0;
}