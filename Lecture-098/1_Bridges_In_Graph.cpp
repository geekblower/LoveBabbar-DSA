#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc,
    vector<int> &low, vector<vector<int>> &result,
    unordered_map<int, list<int>> &adjList, vector<bool> &visited) {

    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neigh : adjList[node]) {
        if(neigh == parent) continue;

        if(visited[neigh] == false) {
            dfs(neigh, node, timer, disc, low, result, adjList, visited);
            low[node] = min(low[node], low[neigh]);

            // Check bridge edge
            if(low[neigh] > disc[node]) {
                result.push_back({node, neigh});
            }
        } else {
            // Back edge found
            low[node] = min(low[node], disc[neigh]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int n, int m) {
    // Create adjList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    int timer = 0;
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    int parent = -1;
    vector<bool> visited(n, false);
    vector<vector<int>> result;

    // DFS
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, parent, timer, disc, low, result, adjList, visited);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> edges;
    int n, m;

    cout << "Enter the value of n : ";
    cin >> n;

    cout << "Enter the value of m : ";
    cin >> m;

    cout << "Enter the edges :" << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    vector<vector<int>> answer = findBridges(edges, n, m);

    cout << "Bridge Edges : ";
    for(int i=0; i<answer.size(); i++) {
        cout << "[" << answer[i][0] << "," << answer[i][1] << "] ";
    }
    cout << endl;

    return 0;
}


/*
    5 6 0 1 0 3 1 3 1 2 2 3 3 4
    5 5 0 1 0 3 0 2 1 2 3 4
    6 7 0 1 0 2 1 2 2 3 3 4 3 5 4 5
*/