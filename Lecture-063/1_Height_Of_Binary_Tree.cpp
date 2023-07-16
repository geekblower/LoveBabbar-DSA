#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int getHeight(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    int answer = max(left, right) + 1;
    return answer;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    int height = getHeight(root);
    cout << endl << "Height / Depth of the tree is : " << height << endl;

    return 0;
}

/*
    INPUT:
        3 4 -1 -1 6 -1 -1
        5 4 2 -1 6 -1 -1 7 -1 8 -1 9 -1 -1 10 -1 -1
        8 2 4 -1 -1 6 2 -1 -1 5 -1 -1 5 -1 9 -1 6 4 2 -1 -1 3 -1 -1 7 -1 -1
*/