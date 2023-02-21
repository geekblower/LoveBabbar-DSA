#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>> arr, int target) {
    int r = 0;
    int c = arr[0].size() - 1;

    while(r<arr.size() && c>=0) {
        if(arr[r][c] == target) {
            return true;
        } else if(arr[r][c] > target) {
            c--;
        } else {
            r++;
        }
    }
// 1 4 7 11 15 2 5 8 12 19 3 6 9 16 22 10 13 14 17 24 18 21 23 26 30
    return false;
}

int main() {
    int row, col, target;
    vector<vector<int>> arr;

    cout << "Enter the number of row & col : ";
    cin >> row >> col;
    
    cout << "Enter the elements of array : ";
    for(int i=0; i<row; i++) {
        vector<int> temp;
        for(int j=0; j<col; j++) {    
            int t;
            cin >> t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }

    cout << "Enter the target : ";
    cin >> target;

    if(binarySearch(arr, target)) {
        cout << "Element is present!" << endl;
    } else {
        cout << "Element is not present!" << endl;
    }

    return 0;
}