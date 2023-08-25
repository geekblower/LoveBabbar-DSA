#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int n, int m, int src) {
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    for(int i=0; i<n-1; i++) {
        
        for(int j=0; j<m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }

    }

    for(int j=0; j<m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(distance[u] + w < distance[v]) {
            return vector<int> (n, INT_MAX);
        }
    }

    return distance;
}

int main() {
    vector<vector<int>> edges;
    int n, m, src;

    cout << "Enter the value of n : ";
    cin >> n;

    cout << "Enter the value of m : ";
    cin >> m;

    cout << "Enter the edges :" << endl;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    cout << "Enter the source node : ";
    cin >> src;

    vector<int> answer = shortestPath(edges, n, m, src);

    cout << "Shortest path from " << src << " : ";
    for(int x : answer) {
        if(x == INT_MAX) {
            cout << "INF ";
        } else {
            cout << x << " ";
        }
    }
    cout << endl;

    return 0;
}


/*
    3 3 0 1 2 1 2 -1 0 2 2
*/