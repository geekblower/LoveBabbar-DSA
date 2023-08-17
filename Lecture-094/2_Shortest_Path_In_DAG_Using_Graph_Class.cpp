#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        unordered_map<int, list<pair<int,int>> > AdjList;

        void addEdge(int u, int v, int weight) {
            AdjList[u].push_back(make_pair(v,weight));
        }

        void printEdge() {
            for(auto x : AdjList) {
                cout << x.first << " -> ";
                for(auto y : x.second) {
                    cout << y.first << "[" << y.second << "]  ";
                }
                cout << endl;
            }
        }

        void solveDFS(stack<int> &st, vector<int> &visited, int node) {
            visited[node] = 1;
            for(pair<int,int> neigh : AdjList[node]) {
                if(visited[neigh.first] == 0) {
                    solveDFS(st, visited, neigh.first);
                }
            }
            st.push(node);
        } 

        stack<int> topoSort() {
            stack<int> st;
            vector<int> visited(6,0);
            
            for(auto x : AdjList) {
                if(visited[x.first] == 0) {
                    solveDFS(st, visited, x.first);
                }
            }

            return st;
        }

        vector<int> shortestPath(int src) {
            vector<int> distance(6, INT_MAX);
            distance[src] = 0;
            stack<int> st = topoSort();

            while(!st.empty()) {
                int val = st.top();
                st.pop();

                if(distance[val] != INT_MAX) {
                    for(auto x : AdjList[val]) {
                        if(distance[val] + x.second < distance[x.first])
                            distance[x.first] = distance[val] + x.second;
                    }
                }
            }

            return distance;
        }
};

int main() {
    Graph G;

    G.addEdge(0, 1, 5);
    G.addEdge(1, 2, 2);
    G.addEdge(1, 3, 6);
    G.addEdge(0, 2, 3);
    G.addEdge(2, 3, 7);
    G.addEdge(3, 4, -1);
    G.addEdge(2, 4, 4);
    G.addEdge(4, 5, -2);
    G.addEdge(2, 5, 2);

    // G.printEdge();

    vector<int> shot = G.shortestPath(1);

    for(auto x : shot) {
        if(x == INT_MAX) {
            cout << "INF" << " ";
        } else {
            cout << x << " ";
        }
    }

    return 0;
}