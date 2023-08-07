#include <bits/stdc++.h>
using namespace std;

/*
int isCyclicDFS(unordered_map<int, list<int> > &adjList, vector<int> &visited, vector<int> &dfsVisited, int Node) {
    if(visited[Node] == 1 && dfsVisited[Node] == 1) {
        return Node;
    }

    visited[Node] = dfsVisited[Node] = 1;

    for(int x : adjList[Node]) {
        int ans = isCyclicDFS(adjList, visited, dfsVisited, x);

        if(ans != -1) {
            return ans;
        }
    }

    dfsVisited[Node] = 0;
    return -1;
}
*/

bool isCyclicDFS(unordered_map<int, list<int> > &adjList, vector<int> &visited, vector<int> &dfsVisited, int Node) {
    visited[Node] = dfsVisited[Node] = 1;

    for(int x : adjList[Node]) {
        if(visited[x] == 0) {
        bool ans = isCyclicDFS(adjList, visited, dfsVisited, x);

            if(ans) {
                return true;
            }
        } else if(dfsVisited[x] == 1) {
            return true;
        }
    }

    dfsVisited[Node] = 0;
    return false;
}

bool detectCyclicInDirectedGraph(int n, vector< pair<int,int> > &edges) {
    unordered_map<int, list<int> > adjList;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
    }

    vector<int> visited(n, 0);
    vector<int> dfsVisited(n, 0);

    for(int i=0; i<n; i++) {
        if(visited[i] == 0) {
            int ans = isCyclicDFS(adjList, visited, dfsVisited, i);

            if(ans) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector< pair<int,int> > edges;
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

    bool answer = detectCyclicInDirectedGraph(n, edges);

    if(answer) {
        cout << "Cycle is Present" << endl;
    } else {
        cout << "Cycle is Not Present" << endl;
    }

    return 0;
}

// 8 9 0 1 1 2 2 6 2 7 7 6 1 3 3 4 4 5 5 3 - YES
// 8 9 0 1 1 2 2 6 2 7 7 6 1 3 3 4 4 5 3 5 - NO