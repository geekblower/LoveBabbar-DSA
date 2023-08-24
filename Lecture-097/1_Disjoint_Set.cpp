#include <bits/stdc++.h>
using namespace std;

vector< pair<pair<int,int>, int> > calculatePrimsMST(vector< vector<int> > &edges, int n, int m) {}

int findParent(vector<int> &parent, int node) {
    // Reached topmost point of hierarchy
    if(parent[node] == node) {
        return node;
    }

    // Going upwards in hierarchy
    /*
        PATH COMPRESSION LOGIC :

        Assigning result to parent[node] to moving it up in
        the hierarchy to make it accessible easily from the top
    */
    return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]) {
        parent[u] = v;
    } else if(rank[v] < rank[u]) {
        parent[v] = u;
        rank[u]++;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

void disjoint(vector< vector<int> > &edges, int n, int m) {
    vector<int> parent(n);
    vector<int> rank(n);

    // Initialising parent & rank
    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
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

    vector< pair<pair<int,int>, int> >  answer = calculatePrimsMST(edges, n, m);

    for(pair<pair<int,int>, int> x : answer) {
        pair<int,int> a = x.first;
        int b = x.second;

        /*
            a.first -> u
            a.second -> v
            b -> weight
        */
        cout << a.first << "-" << a.second << " : " << b << endl;
    }

    return 0;
}

// 5 6 0 3 6 0 1 2 1 3 8 1 4 5 1 2 3 2 4 7