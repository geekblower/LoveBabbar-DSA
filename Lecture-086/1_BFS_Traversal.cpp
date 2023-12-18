#include <bits/stdc++.h>
using namespace std;

void traversal(map <int, set<int> > &adjset, map <int, bool> &visited, vector<int> &answer, int node) {
    queue<int> Q;
    Q.push(node);
    visited[node] = 1;

    while(!Q.empty()) {
        int frontVal = Q.front();
        Q.pop();
        //visited[frontVal] = true;
        answer.push_back(frontVal);
 
        for(auto i : adjset[frontVal]) {
            if(!visited[i]) {
                Q.push(i);
                visited[i]=1;
            }
        }
    }
}

vector<int> bfsOfGraph(int vertex, vector< pair<int, int> > edges) {
    map <int, set<int> > adjset;
    vector<int> answer;
    map <int, bool> visited; //default F
    
    // Creating Adjacency set
    for(int i=0; i<edges.size( ); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
 
        adjset[u].insert(v);
        adjset[v].insert(u);    
    }

    //traversal(adjset, visited, answer, 0); if not disconnected

    //Traversing all components of a graph for disconnected components
    for (const auto& pair : adjset) {
        if(!visited[pair.first]) {
            //cout<<pair.first<<" ";
            traversal(adjset, visited, answer, pair.first);
        }
    } 

    return answer;
}

int main() {
    int n, m;

    cout << "Enter the number of nodes : ";
    cin >> n;

    cout << "Enter the number of edges : ";
    cin >> m;

    vector< pair<int,int> > edges(m, {0,0});

    for(int i=0; i<m; i++) {
        cin >> edges[i].first;
        cin >> edges[i].second; 
    }

    vector<int> solution = bfsOfGraph(n, edges);

    cout << "bfsOfGraph Traversal : ";
    for(auto i : solution) {
        cout << i << " ";
    }
    cout << endl;

    return 0; 
}

/* 
Indexes
0 1
1 2
2 3
3 4
4 1 
*/

/*  
Node values
1 2
2 3
3 5
5 7
7 2
*/

