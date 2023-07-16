#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

vector<int> Diagonal(Node* root) {
    if(root == NULL) {
        return {};
    }

    vector<int> answer;
    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()) {
        Node* FrontNode = Q.front();
        Q.pop();
        
        if(FrontNode->left) {
            Q.push(FrontNode->left);
        }
        
        while(FrontNode->right) {
            answer.push_back(FrontNode->data);
            FrontNode = FrontNode->right;

            if(FrontNode->left) {
                Q.push(FrontNode->left);
            } 
        }
        
        answer.push_back(FrontNode->data);
    }
    
    return answer;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    vector<int> answer = Diagonal(root);

    cout << endl << "Diagonal Traversal : ";
    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}

/*
    INPUT:
        2 3 5 -1 -1 -1 4 6 -1 -1 7 -1 -1
        2 3 8 -1 -1 7 -1 -1 4 -1 5 6 -1 -1 -1
*/