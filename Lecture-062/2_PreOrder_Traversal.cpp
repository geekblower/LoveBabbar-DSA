#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

void preOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}

int main() {
    Node* root = NULL;

    // Creating a tree
    root = buildTree(root);

    cout << "\nPre Order Traversal : " << endl;
    preOrderRecursive(root);

    return 0;
}

// INPUT : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1