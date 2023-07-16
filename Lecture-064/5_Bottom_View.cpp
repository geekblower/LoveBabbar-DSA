#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

vector<int> BottomView(Node* root) {
    if(root == NULL) {
        return {};
    }

    vector<int> answer;

    map<int, int> BottomNode;
    queue<pair<Node*, int> > Q;
    Q.push(make_pair(root, 0));

    while(!Q.empty()) {
        pair<Node*, int> temp = Q.front();
        Q.pop();

        Node* FrontNode = temp.first;
        int HorizDist = temp.second;

        BottomNode[HorizDist] = FrontNode->data;

        if(FrontNode->left) {
            Q.push(make_pair(FrontNode->left, HorizDist-1));
        }

        if(FrontNode->right) {
            Q.push(make_pair(FrontNode->right, HorizDist+1));
        }
    }

    for(auto i : BottomNode) {
        answer.push_back(i.second);
    }

    return answer;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    vector<int> answer = BottomView(root);

    cout << endl << "Bottom View : ";
    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}

/*
    INPUT:
        1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
        1 2 -1 4 5 -1 -1 -1 3 -1 -1
        1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
*/