#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

pair<bool, int> isSumTree(Node* root) {
    if(root == NULL) {
        return {true, 0};
    }
    
    if(root->left == NULL && root->right == NULL) {
        return {true, root->data};
    }

    pair<bool, int> Left = isSumTree(root->left);
    pair<bool, int> Right = isSumTree(root->right);

    bool sum = root->data == (Left.second + Right.second);

    pair<bool, int> ans;
    ans.first = (Left.first && Right.first && sum);
    ans.second = 2 * root->data;

    return ans;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    bool check = isSumTree(root).first;

    if(check) {
        cout << endl << "Sum Tree!" << endl;
    } else {
        cout << endl << "Not a sum Tree!" << endl;
    }

    return 0;
}

/*
    INPUT:
        3 1 -1 -1 2 -1 -1
        28 8 4 -1 4 -1 -1 -1 6 -1 3 2 -1 -1 1 -1 -1
        14 18 4 -1 4 -1 -1 -1 6 -1 3 2 -1 -1 1 -1 -1
        14 8 4 -1 4 -1 -1 -1 6 -1 3 2 -1 -1 -1
*/