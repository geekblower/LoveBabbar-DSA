#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector< vector<int> > suduko, int val) {
    for(int i=0; i<9; i++) {
        // Row check
        if(suduko[row][i] == val) {
            return false;
        }

        // Column Check
        if(suduko[i][col] == val) {
            return false;
        }

        // 3x3 Matrix Check
        if(suduko[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
            return false;
        }
    }

    return true;
}

bool solve(vector< vector<int> > &suduko) {
    for(int row=0; row<9; row++) {
        for(int col=0; col<9; col++) {
            
            // Empty Cell
            if(suduko[row][col] == 0) {

                for(int val=1; val<=9; val++) {
                    if(isSafe(row, col, suduko, val)) {
                        suduko[row][col] = val;

                        bool nextSol = solve(suduko);
                        if(nextSol) {
                            return true;
                        } else {
                            suduko[row][col] = 0;
                        }

                    }
                }

                return false;
            }

        }
    }

    return true;
}

void validSuduko(vector< vector<int> > &suduko) {
    solve(suduko);
}

int main() {
    vector< vector<int> > suduko(9, vector<int> (9,0));

    cout << "Enter the suduko : " << endl;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> suduko[i][j];
        }
    }

    validSuduko(suduko);

    cout << "Solved Suduko : " << endl;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << suduko[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/