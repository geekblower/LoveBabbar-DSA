#include <bits/stdc++.h>
using namespace std;

bool isCyclicBFS(unordered_map<int, list<int> > &adjList, unordered_map<int, bool> &visited, int Node) {
    unordered_map<int, int> parent;
    parent[Node] = -1;
    visited[Node] = true;

    queue<int> Q;
    Q.push(Node);

    while(!Q.empty()) {
        int FrontVal = Q.front();
        Q.pop();

        for(int i : adjList[FrontVal]) {
            if(visited[i] == true && parent[FrontVal] != i) {
                return true;
            }

            if(visited[i] == false) {
                visited[i] = true;
                parent[i] = FrontVal;
                Q.push(i);
            }
        }
    }

    return false;
}

string cycleDetection(vector<vector<int> > &edges, int n, int m) {
    unordered_map<int, list<int> > adjList;
    unordered_map<int, bool> visited;

    // Creating Adjacency List
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == false) {
            bool ans = isCyclicBFS(adjList, visited, i);
            
            if(ans) {
                return "YES";
            }
        }
    }

    return "NO";
}

int main() {
    int n, m;
    vector<vector<int> > edges;

    cout << "Enter the total number of nodes : ";
    cin >> n;

    cout << "Enter total number of edges : ";
    cin >> m;

    cout << "Enter edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    string ans = cycleDetection(edges, n, m);

    cout << "Cycle Detection Result : " << ans << endl;

    return 0;
}
