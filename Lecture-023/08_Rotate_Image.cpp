#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &arr) {
    int row = arr.size();
    int col = arr[0].size();
    vector<vector<int>> temp(arr);

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            temp[j][col-i-1] = arr[i][j];
        }
    }

    arr = temp;
}

int main() {
    int row, col, target;
    vector<vector<int>> arr;

    cout << "Enter the number of row & col : ";
    cin >> row >> col;
    
    cout << "Enter the elements of array : " << endl;
    for(int i=0; i<row; i++) {
        vector<int> temp;
        for(int j=0; j<col; j++) {    
            int t;
            cin >> t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }

    cout << endl << "Before Rotate : " << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    rotateMatrix(arr);

    cout << endl << "After Rotate : " << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
