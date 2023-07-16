#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

vector<int> VerticalOrder(Node* root) {
    if(root == NULL) {
        return {};
    }

    vector<int> answer;
    map<int, map<int, vector<int> > > NodeMap;
    queue<pair<Node*, pair<int, int> > > Q;

    Q.push(make_pair(root, make_pair(0,0)));

    while(!Q.empty()) {
        pair<Node*, pair<int, int> > temp = Q.front();
        Q.pop();

        Node* FrontNode = temp.first;
        int HorizDist = temp.second.first;
        int Lvl = temp.second.second;

        NodeMap[HorizDist][Lvl].push_back(FrontNode->data);

        if(FrontNode->left) {
            Q.push(make_pair(FrontNode->left, make_pair(HorizDist-1, Lvl+1)));
        }

        if(FrontNode->right) {
            Q.push(make_pair(FrontNode->right, make_pair(HorizDist+1, Lvl+1)));
        }
    }

    for(auto i : NodeMap) {
        for(auto j : i.second) {
            for(auto k : j.second) {
                
                answer.push_back(k);

            }
        }
    }

    return answer;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    vector<int> answer = VerticalOrder(root);

    cout << endl << "Vertical Order Traversal : ";
    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}

/*
    INPUT:
        1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
        1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
*/