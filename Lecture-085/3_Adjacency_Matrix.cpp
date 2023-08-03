#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        vector< vector<int> > adjMat;

        Graph(int nodeCount) {
            adjMat = vector < vector<int> > (nodeCount, vector<int> (nodeCount, 0));
        }

        void addEdge(int u, int v, bool direction) {
            // direction = false -> undirected graph
            // direction = true -> directed graph

            // create an edge from u to v
            adjMat[u][v] = 1;

            if(direction == false) {
                adjMat[v][u] = 1;
            }
        }

        void printAdjMatrix(){
            for(int i=0; i<adjMat.size(); i++) {
                cout << i << " -> ";

                for(int j=0; j<adjMat.size(); j++) {
                    cout << adjMat[i][j] << " ";
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

    Graph G(n);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        G.addEdge(u, v, 0);
    }

    // Printing graph
    G.printAdjMatrix();

    return 0;
}