#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPrint(vector<vector<int>> arr) {
    vector<int> spiral;
    int row = arr.size();
    int col = arr[0].size();
    
    int top=0, bottom=row-1, left=0, right=col-1;
    int countElements = 0;
    int totalElements = row * col;

    while(countElements < totalElements) {
        // Printing Top Row
        for(int i=left; i<=right && countElements<totalElements; i++) {
            spiral.push_back(arr[top][i]);
            countElements++;
        }
        top++;

        // Printing Right Column
        for(int i=top; i<=bottom && countElements<totalElements; i++) {
            spiral.push_back(arr[i][right]);
            countElements++;
        }
        right--;

        // Printing Bottom Row
        for(int i=right; i>=left && countElements<totalElements; i--) {
            spiral.push_back(arr[bottom][i]);
            countElements++;
        }
        bottom--;

        // Printing Left Column
        for(int i=bottom; i>=top && countElements<totalElements; i--) {
            spiral.push_back(arr[i][left]);
            countElements++;
        }
        left++;
    }

    return spiral;
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

    vector<int> spiral = spiralPrint(arr);

    cout << "Spiral print of array : ";
    for(int i:spiral) {
        cout << i << " ";
    }

    return 0;
}