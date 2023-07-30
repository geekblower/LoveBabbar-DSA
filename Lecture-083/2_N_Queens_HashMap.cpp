#include <bits/stdc++.h>
using namespace std;

map<int, bool> rowCheck;
map<int, bool> upperCheck;
map<int, bool> lowerCheck;

void addSolution(vector< vector<int> > board, vector< vector<int> > &sol) {
    vector<int> temp;
    for(vector<int> x : board) {
        for(int y : x) {
            temp.push_back(y);
        }
    }
    sol.push_back(temp);
}

bool isSafe(int row, int col, int n) {
    return !(rowCheck[row] == true || lowerCheck[row+col] == true || upperCheck[n+row-col] == true);
}

void solve(int col, vector< vector<int> > &solution, vector< vector<int> > &board, int n) {
    // Base Case
    if(col == n) {
        addSolution(board, solution);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, n)) {
            // Setting Queen
            board[row][col] = 1;

            // Mapping Queen
            rowCheck[row] = true;
            lowerCheck[row+col] = true;
            upperCheck[n+row-col] = true;

            // Recursive Call
            solve(col+1, solution, board, n);

            // Backtracking
            board[row][col] = 0;
            rowCheck[row] = false;
            lowerCheck[row+col] = false;
            upperCheck[n+row-col] = false;
        }
    }
}

vector< vector<int> > nQueens(int n) {
    vector< vector<int> > solution;
    vector< vector<int> > board(n, vector<int> (n,0));

    solve(0, solution, board, n);
    return solution;
}

int main() {
    int n;
    cout << "Enter the value of n : ";
    cin >> n;

    vector< vector<int> > solution = nQueens(n);
    int i = 0;

    for(vector<int> x : solution) {
        cout << endl << "Possible Configuration [" << ++i << "] : ";
        for(int y : x) {
            cout << y << " ";
        }
    }

    return 0;
}