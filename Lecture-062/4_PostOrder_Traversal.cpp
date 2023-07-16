#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

void postOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    // Creating a tree
    root = buildTree(root);

    cout << "\nPost Order Traversal : " << endl;
    postOrderRecursive(root);

    return 0;
}

// INPUT : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1