#include <bits/stdc++.h>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr) {
    int row = arr.size();
    int col = arr[0].size();
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
    vector<vector<int>> arr;

    cout << "Enter the number of row & col : ";
    cin >> row >> col;
    
    cout << "Enter the elements of array : \n";
    for(int i=0; i<row; i++) {
        vector<int> temp;
        for(int j=0; j<col; j++) {    
            int t;
            cin >> t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }

    vector<int> wave = wavePrint(arr);

    cout << "Wave print of array : ";
    for(int i:wave) {
        cout << i << " ";
    }

    return 0;
}
