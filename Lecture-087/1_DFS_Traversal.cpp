#include <bits/stdc++.h>
using namespace std;

void traversal(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, vector<int> &component, int node) {
    component.push_back(node);
    visited[node] = 1;

    for(auto i : adjList[node]) {
        if(!visited[i]) {
            traversal(adjList, visited, component, i);
        }
    }

}

vector< vector<int> > DFS(int V, int E, vector< vector<int> > &edges) {
    unordered_map<int, list<int> > adjList;
    vector< vector<int> > answer;
    unordered_map<int, bool> visited;
    
    // Creating Adjacency List
    for(int i=0; i<edges.size( ); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Traversing all components of a graph
    for(int i=0; i<V; i++) {
        if(!visited[i]) {
            vector<int> component;
            traversal(adjList, visited, component, i);
            answer.push_back(component);
        }
    }

    return answer;
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

    vector< vector<int> > solution = DFS(n, m, edges);

    cout << "DFS Traversal : ";
    for(auto i : solution) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    /*
    for(int i=0; i<solution.size(); i++) {
        for(int j=0; j<solution.size(); j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}