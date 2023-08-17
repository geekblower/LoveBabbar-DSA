#include <bits/stdc++.h>
using namespace std;

void solveDFS(unordered_map< int, list<pair<int,int>> > &adjList, stack<int> &st, vector<int> & visited, int node) {
    visited[node] = 1;

    for(pair<int,int> neigh : adjList[node]) {
        if(visited[neigh.first] == 0) {
            solveDFS(adjList, st, visited, neigh.first);
        }
    }

    st.push(node);
}

stack<int> topoSort(unordered_map< int, list<pair<int,int>> > adjList, int n) {
    stack<int> st;
    vector<int> visited(n,0);

    for(auto x : adjList) {
        if(visited[x.first] == 0) {
            solveDFS(adjList, st, visited, x.first);
        }
    }

    return st;
}

vector<int> shortestPath(vector< vector<int> > &edges, int n, int m, int src) {
    // Creating adj list
    unordered_map< int, list<pair<int,int>> > adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v,w});
    }

    stack<int> st = topoSort(adjList, n);
    stack<int> temp = st;
    while(!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Initialising distance vector
    vector<int> distance(n,INT_MAX);
    distance[src] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if(distance[node] != INT_MAX) {
            for(auto x : adjList[node]) {
                if(distance[node] + x.second < distance[x.first]) {
                    distance[x.first] = distance[node] + x.second;
                }
            }
        }
    }

    return distance;
}

int main() {
    vector<vector<int>> edges;
    int n, m, src;

    cout << "Enter the number of nodes : ";
    cin >> n;
    
    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    cout << "Enter the source : ";
    cin >> src;

    vector<int> answer = shortestPath(edges, n, m, src);
    cout << "The shortest path : ";
    for(int x : answer) {
        cout << x << " ";
    }

    return 0;
}

// 6 9 0 1 5 1 2 2 1 3 6 0 2 3 2 3 7 3 4 -1 2 4 4 4 5 -2 2 5 2