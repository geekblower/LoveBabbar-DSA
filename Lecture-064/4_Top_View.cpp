#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

void TraverseLeft(Node* root, vector<int>& answer) {
    if(root == NULL) {
        return;
    }

    TraverseLeft(root->left, answer);
    answer.push_back(root->data);
}

void TraverseRight(Node* root, vector<int>& answer) {
    if(root == NULL) {
        return;
    } 

    answer.push_back(root->data);
    TraverseRight(root->right, answer);
}

vector<int> TopView(Node* root) {
    if(root == NULL) {
        return {};
    }

    vector<int> answer;

    // Left Part
    TraverseLeft(root->left, answer);

    // Root Node
    answer.push_back(root->data);

    // Right Part
    TraverseRight(root->right, answer);

    return answer;
}

vector<int> TopView2(Node* root) {
    if(root == NULL) {
        return {};
    }

    vector<int> answer;
    map<int, int> TopNode;
    queue<pair<Node*, int> > Q;

    Q.push(make_pair(root, 0));

    while(!Q.empty()) {
        pair<Node*, int> temp = Q.front();
        Q.pop();

        Node* FrontNode = temp.first;
        int HorizDist = temp.second;

        // If one value is present for a HD, then do nothing
        if(TopNode.find(HorizDist) == TopNode.end()) {
            TopNode[HorizDist] = FrontNode->data;
        }

        if(FrontNode->left) {
            Q.push(make_pair(FrontNode->left, HorizDist-1));
        }

        if(FrontNode->right) {
            Q.push(make_pair(FrontNode->right, HorizDist+1));
        }
    }

    for(auto i : TopNode) {
        answer.push_back(i.second);
    }

    return answer;
}


int main() {
    Node* root = NULL;

    root = buildTree(root);
    vector<int> answer = TopView2(root);

    cout << endl << "Top View : ";
    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}

/*
    INPUT:
        1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
        1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
        1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
*/