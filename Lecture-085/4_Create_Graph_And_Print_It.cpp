#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > printAdjacency(int n, int m, vector< vector<int> > &edges) {
    vector< vector<int> > solution(n);

    for(int i=0; i<n; i++) {
        solution[i].push_back(i);
    }

    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        solution[u].push_back(v);
        solution[v].push_back(u);
    }

    return solution;
}

int main() {
    int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    vector< vector<int> > edges(m, {0,0});

    for(int i=0; i<m; i++) {
        cin >> edges[i][0];
        cin >> edges[i][1];
    }

    vector< vector<int> > solution = printAdjacency(n, m, edges);

    for(auto i : solution) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}