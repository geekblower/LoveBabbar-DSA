#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

vector<int> ZigZag(Node* root) {
    if(root == NULL) {
        return {};
    }

    queue<Node*> Q;
    vector<int> answer;

    Q.push(root);
    bool L2R = true;

    while(!Q.empty()) {
        int size = Q.size();
        vector<int> result(size);

        // Level Process
        for(int i=0; i<size; i++) {
            Node* FrontNode = Q.front();
            Q.pop();

            int index = L2R ? i : size-i-1;
            result[index] = FrontNode->data;

            if(FrontNode->left) {
                Q.push(FrontNode->left);
            }

            if(FrontNode->right) {
                Q.push(FrontNode->right);
            }
        }
        
        // Change Direction
        L2R = !L2R;

        for(auto i : result) {
            answer.push_back(i);
        }
    }

    return answer;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    vector<int> answer = ZigZag(root);

    cout << endl << "Zigzag Traversal : ";
    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}

/*
    INPUT:
        1 2 3 -1 -1 5 -1 -1 4 -1 6 7 -1 -1 8 -1 -1
        7 9 8 10 -1 -1 9 -1 -1 8 -1 -1 7 6 -1 -1 -1
*/