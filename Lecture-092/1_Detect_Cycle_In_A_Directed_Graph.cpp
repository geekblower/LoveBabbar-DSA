#include <bits/stdc++.h>
using namespace std;

bool detectCyclicInDirectedGraph(int n, vector< pair<int,int> > &edges) {
    unordered_map<int, list<int> > adjList;
    vector<int> indegree(n,0);
    queue<int> qu;
    int count = 0;

    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        indegree[v]++;
    }

    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            qu.push(i);
        }
    }

    while(!qu.empty()) {
        count++;

        int frontVal = qu.front();
        qu.pop();

        for(int x : adjList[frontVal]) {
            indegree[x]--;

            if(indegree[x] == 0) {
                qu.push(x);
            }
        }
    }

    return (count == n) ? false: true;
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