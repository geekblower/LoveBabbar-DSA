#include <bits/stdc++.h>
using namespace std;

void solveDFS(unordered_map<int, list<int> > &adjList, stack<int> &st, vector<bool> &visited, int node) {
    visited[node] = true;

    for(auto x : adjList[node]) {
        if(!visited[x]) {
            solveDFS(adjList, st, visited, x);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector< vector<int> > &edges, int v, int e) {
    unordered_map<int, list<int> > adjList;
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }

    vector<int> solution;
    stack<int> st;
    vector<bool> visited(v,0);

    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            solveDFS(adjList, st, visited, i);
        }
    }

    while(!st.empty()) {
        solution.push_back(st.top());
        st.pop();
    }

    return solution;
}

int main() {
    vector< vector<int> > edges;
    int n, m;

    cout << "Enter number of nodes : ";
    cin >> n;

    cout << "Enter number of edges : ";
    cin >> m;

    cout << "Enter edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    vector<int> topSort = topologicalSort(edges, n, m);

    cout << "Topological Sort : ";
    for(int x : topSort) {
        cout << x << " ";
    }

    return 0;
}

// 4 4 0 1 1 2 0 3 3 2
// 6 7 0 1 0 2 1 3 2 3 3 4 3 5 4 5