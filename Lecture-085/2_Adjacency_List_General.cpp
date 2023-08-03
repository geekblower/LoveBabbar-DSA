#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graph {
    public:
        unordered_map<T, list<T> > adj;

        void addEdge(T u, T v, bool direction) {
            // direction = false -> undirected graph
            // direction = true -> directed graph

            // create an edge from u to v
            adj[u].push_back(v);

            if(direction == false) {
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i : adj) {
                cout << i.first << " -> ";

                for(auto j : i.second) {
                    cout << j << " ";
                }

                cout << endl;
            }
        }
};

int main() {

    int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;


    Graph<int> G;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v, 0);
    }

    // Printing graph
    G.printAdjList();

    return 0;
}