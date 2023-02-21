#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>> arr, int target) {
    int row = arr.size();
    int col = arr[0].size();
    int start = 0;
    int end = (row*col) - 1;

    while(start <= end) {
        int mid = start + (end-start)/2;
        int r = mid / col;
        int c = mid % col;

        if(arr[r][c] == target) {
            return true;
        } else if(arr[r][c] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

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