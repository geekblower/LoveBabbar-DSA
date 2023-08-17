#include <bits/stdc++.h>
using namespace std;

vector< pair<pair<int,int>, int> > calculatePrimsMST(vector< vector<int> > &edges, int n, int m) {
    // Creating adj list
    unordered_map< int, list<pair<int,int>> > adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    // Initiaising the required data structures
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    // Initialising src node
    key[0] = 0;
    
    for(int i=0; i<n; i++) {
        // Calculating minimum from key vector
        int u, mini = INT_MAX;
        for(int i=0; i<key.size(); i++) {
            if(key[i] < mini && mst[i] == false) {
                u = i;
                mini = key[i];
            }
        }

        mst[u] = true;

        for(pair<int,int> x : adjList[u]) {
            if(mst[x.first] == false && x.second < key[x.first]) {
                key[x.first] = x.second;
                parent[x.first] = u;
            }
        }
    }

    vector< pair<pair<int,int>, int> > answer;
    for(int i=1; i<n; i++) {
        answer.push_back({{parent[i], i}, key[i]});
    }

    return answer;
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