#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

void LeftView(Node* root, vector<int>& answer, int lvl) {
    if(root == NULL) {
        return;
    }

    if(lvl == answer.size()) {
        answer.push_back(root->data);
    }

    LeftView(root->left, answer, lvl+1);
    LeftView(root->right, answer, lvl+1);
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    vector<int> answer;
    LeftView(root, answer, 0);

    cout << endl << "Left View : ";
    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}

/*
    INPUT:
        1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
        1 2 -1 4 5 -1 -1 -1 3 -1 -1
        1 2 3 -1 -1 4 -1 7 -1 -1 5 -1 6 -1 8 -1 9 -1 -1
*/