#include <bits/stdc++.h>
using namespace std;

void addSolution(vector< vector<int> > board, vector< vector<int> > &sol) {
    vector<int> temp;
    for(vector<int> x : board) {
        for(int y : x) {
            temp.push_back(y);
        }
    }
    sol.push_back(temp);
}

bool isSafe(int row, int col, vector< vector<int> > board, int n) {
    // Checking for same row
    for(int j=col; j>=0; j--) {
        if(board[row][j] == 1) {
            return false;
        }
    }

    // Checking for left upper diagonal
    for(int i=row, j=col; i>=0 && j>=0; i--, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    
    // Checking for left lower diagonal
    for(int i=row, j=col; i<n && j>=0; i++, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solve(int col, vector< vector<int> > &solution, vector< vector<int> > &board, int n) {
    // Base Case
    if(col == n) {
        addSolution(board, solution);
        return;
    }

    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col+1, solution, board, n);

            // Backtracking
            board[row][col] = 0;
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