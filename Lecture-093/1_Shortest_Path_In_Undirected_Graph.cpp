#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector< pair<int,int> > &edges, int n, int m, int src, int tar) {
    // Creating adj list
    unordered_map< int, list<int> > adjList;
    for(int i=0; i<n; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> visited(n,0);
    vector<int> parent(n,0);
    queue<int> qu;

    qu.push(src);
    visited[src] = 1;
    parent[src] = -1;

    while(!qu.empty()) {
        int val = qu.front();
        qu.pop();

        for(int x : adjList[val]) {
            if(visited[x] == 0) {
                visited[x] = 1;
                parent[x] = val;
                qu.push(x);
            }
        }
    }

    vector<int> solution;
    while(tar != src) {
        solution.push_back(tar);
        tar = parent[tar];
    }
    solution.push_back(src);

    reverse(solution.begin(), solution.end());
    return solution;
}

int main() {
    vector< pair<int,int> > edges;
    int n, m, src, tar;

    cout << "Enter the number of nodes : ";
    cin >> n;
    
    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u,v));
    }

    cout << "Enter the source and target : ";
    cin >> src >> tar;

    vector<int> answer = shortestPath(edges, n, m, src, tar);
    cout << "The shortest path : ";
    for(int x : answer) {
        cout << x << " ";
    }

    return 0;
}

// 8 9 0 1 0 2 0 3 1 4 2 7 3 5 5 6 6 7 4 7