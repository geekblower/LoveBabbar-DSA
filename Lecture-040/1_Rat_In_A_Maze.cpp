#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector< vector<int> > maze, vector< vector<int> > visited, int newx, int newy) {
    // Valid index
    if((newx>=0 && newx<maze.size()) && (newy>=0 && newy<maze.size())) {
        // Valid path
        if(maze[newx][newy] == 1 && visited[newx][newy] == 0) {
            return true;
        }
    }

    return false;
}

void findPath(vector< vector<int> > maze, vector<string> &solution, vector< vector<int> > &visited, string output, int x, int y) {
    if(x==maze.size()-1 && y==maze.size()-1) {
        solution.push_back (output);
        return;
    }
    
    visited[x][y] = 1;
    int newx, newy;

    // Up
    newx = x-1;
    newy = y;
    if(isPossible(maze, visited, newx, newy)) {
        output.push_back ('U');
        findPath(maze, solution, visited, output, newx, newy);
        output.pop_back();
    }

    // Down
    newx = x+1;
    newy = y;
    if(isPossible(maze, visited, newx, newy)) {
        output.push_back ('D');
        findPath(maze, solution, visited, output, newx, newy);
        output.pop_back();
    }
    
    // Left
    newx = x;
    newy = y-1;
    if(isPossible(maze, visited, newx, newy)) {
        output.push_back ('L');
        findPath(maze, solution, visited, output, newx, newy);
        output.pop_back();
    }
    
    // Right
    newx = x;
    newy = y+1;
    if(isPossible(maze, visited, newx, newy)) {
        output.push_back ('R');
        findPath(maze, solution, visited, output, newx, newy);
        output.pop_back();
    }

    visited[x][y] = 0;
}

int main() {
    int size;
    cout << "Enter the row & col size : ";
    cin >> size;

    vector< vector<int> > maze;
    cout << "Enter the elements of maze : ";
    for(int i=0; i<size; i++) {
        vector<int> temp(size);
        for(int j=0; j<size; j++) {
            cin >> temp[j];
        }
        maze.push_back (temp);
    }

    vector<string> solution;
    string output;

    // Creating a visited vector to keep the track of visited points
    vector< vector<int> > visited (maze);
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            visited[i][j] = 0;
        }
    }

    findPath(maze, solution, visited, output, 0, 0);
    sort(solution.begin(), solution.end());

    cout << "All possible paths : " << endl;
    for(int i=0; i<solution.size(); i++) {
        cout << solution[i] << endl;
    }

    return 0;
}

// 1 0 0 0 1 1 0 1 1 1 0 0 0 1 1 1
