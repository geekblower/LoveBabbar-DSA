#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector< vector<int> > maze, vector< vector<int> > visited, int n, int newX, int newY) {
    return ((newX >= 0) && (newX < n) && (newY >= 0) && (newY < n) && (maze[newX][newY] == 1) && (visited[newX][newY] == 0));
}

void paths(vector<string> &answer, vector< vector<int> > &maze, vector< vector<int> > &visited, string path, int x, int y, int n) {
    if(x == n-1 && y == n-1) {
        answer.push_back(path);
        return;
    }

    int newX, newY;

    // Down Movement - 'D'
    newX = x+1;
    newY = y;
    if(isSafe(maze, visited, n, newX, newY)) {
        visited[newX][newY] = 1;
        path.push_back('D');
        paths(answer, maze, visited, path, newX, newY, n);
        visited[newX][newY] = 0;
        path.pop_back();
    }

    // Left Movement - 'L'
    newX = x;
    newY = y-1;
    if(isSafe(maze, visited, n, newX, newY)) {
        visited[newX][newY] = 1;
        paths(answer, maze, visited, path+'L', newX, newY, n);
        visited[newX][newY] = 0;
    }

    // Right Movement - 'R'
    newX = x;
    newY = y+1;
    if(isSafe(maze, visited, n, newX, newY)) {
        visited[newX][newY] = 1;
        paths(answer, maze, visited, path+'R', newX, newY, n);
        visited[newX][newY] = 0;
    }

    // Up Movement - 'U'
    newX = x-1;
    newY = y;
    if(isSafe(maze, visited, n, newX, newY)) {
        visited[newX][newY] = 1;
        paths(answer, maze, visited, path+'U', newX, newY, n);
        visited[newX][newY] = 0;
    }
}

vector<string> searchMaze(vector< vector<int> > &arr, int n) {
    vector< vector<int> > visited(n, vector<int> (n,0));
    vector<string> answer;

    if(arr[0][0] != 0) {
        paths(answer, arr, visited, "", 0, 0, n);
    }

    return answer;
}

int main() {
    vector< vector<int> > maze;
    int n = 4;

    cout << "Enter the maze : " << endl;
    for(int i=0; i<n; i++) {
        vector<int> temp(n);
        for(int j=0; j<n; j++) {
            cin >> temp[j];
        }
        maze.push_back(temp);
    }

    vector<string> path = searchMaze(maze, n);

    cout << "All possible paths : ";
    for(string s : path) {
        cout << s << " ";
    }

    return 0;
}

/*
1 0 0 0
1 1 0 0
1 1 0 0
0 1 1 1
*/