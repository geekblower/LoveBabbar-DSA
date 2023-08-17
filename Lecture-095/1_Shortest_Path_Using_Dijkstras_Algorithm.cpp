#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector< vector<int> > &edges, int n, int m, int src) {
    // Creating adj list
    unordered_map< int, list<pair<int,int>> > adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    vector<int> distance(n,INT_MAX);
    set<pair<int,int>> st;

    distance[src] = 0;
    st.insert({0,src});

    while(!st.empty()) {
        // Fetching top pair
        pair<int,int> curr = *(st.begin());

        int nodeDistance = curr.first;
        int topNode = curr.second;

        // Removing top pair
        st.erase(st.begin());

        for(auto neigh : adjList[topNode]) {
            if(nodeDistance + neigh.second < distance[neigh.first]) {
                auto record = st.find({distance[neigh.first], neigh.first});

                // Erasing old record
                if(record != st.end()) {
                    st.erase(record);
                }

                // Upadting distance
                distance[neigh.first] = nodeDistance + neigh.second;
                
                // Inserting new pair in set
                st.insert({distance[neigh.first], neigh.first});
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

// 4 5 0 1 5 1 2 9 1 3 2 2 3 6 0 2 8
// 5 7 2 1 3 1 4 1 0 3 2 2 0 1 1 0 7 1 3 5 3 4 7