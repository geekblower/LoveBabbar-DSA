#include <bits/stdc++.h>
using namespace std;

void solveDFS(vector<int> &solution, unordered_map<int, list<int> > &adjlist, queue<int> &qu, vector<int> &indegree, vector<bool> &visited) {
    if(qu.empty()) {
        return;
    }

    int frontVal = qu.front();
    qu.pop();
    solution.push_back(frontVal);
    visited[frontVal] = 1;
    
    for(int x : adjlist[frontVal]) {
        indegree[x]--;
        
        if(!visited[x] && indegree[x] == 0) {
            qu.push(x);
            //visited[x]=1 also correct
        }
    }

    solveDFS(solution, adjlist, qu, indegree, visited);
}

vector<int> topologicalSort(vector< vector<int> > &edges, int v, int e) {
    unordered_map<int, list<int> > adjlist;
    vector<int> indegree(v,0);
    queue<int> qu;
    vector<bool> visited(v,0);
    vector<int> solution;

    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        indegree[v]++;
    }

    for(int i=0; i<v; i++) {
        if(indegree[i] == 0) {
            qu.push(i);
        }
        if(!visited[i]) {
            solveDFS(solution, adjlist, qu, indegree, visited);
        }
    }

    return solution;
}

int main() {
    int t;
    cin>>t;
    while(t--){
    vector< vector<int> > edges;
    int n, m;

    //cout << "Enter number of nodes : ";
    cin >> n;

    //cout << "Enter number of edges : ";
    cin >> m;

    //cout << "Enter edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    vector<int> topSort = topologicalSort(edges, n, m);

    //cout << "Topological Sort : ";
    for(int x : topSort) {
        cout << x << " ";
    }

    cout<<endl;

    }

    return 0;
}

// 4 4 0 1 1 2 0 3 3 2

/* 
6 7
0 1
1 3
3 5
4 5
3 4
2 3
0 2 
Sort -> 0 1 2 3 4 5*/
