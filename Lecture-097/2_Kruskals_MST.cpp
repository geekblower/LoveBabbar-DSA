#include <bits/stdc++.h>
using namespace std;

// Writing own compare method to sort vector according to their 2nd index
bool compare(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

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

int calculateKruskalsMST(vector< vector<int> > &edges, int n) {
    vector<int> parent(n);
    vector<int> rank(n);

    // Initialising parent & rank
    for(int i=0; i<n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sorting vector according to their weight
    sort(edges.begin(), edges.end(), compare);
    
    // Answer variable used to sum up the weights of nodes added in MST
    int minWeight = 0;

    for(int i=0; i<edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);

        if(u != v) {
            unionSet(u, v, parent, rank);
            minWeight += edges[i][2];
        }
    }

    return minWeight;
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

    int minWeight = calculateKruskalsMST(edges, n);

    cout << "Weight of Kruskal's MST : " << minWeight << endl;

    return 0;
}

// 5 6 0 3 6 0 1 2 1 3 8 1 4 5 1 2 3 2 4 7