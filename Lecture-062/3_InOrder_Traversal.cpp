#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

void inOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

int main() {
    Node* root = NULL;

    // Creating a tree
    root = buildTree(root);

    cout << "\nIn Order Traversal : " << endl;
    inOrderRecursive(root);

    return 0;
}

// INPUT : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1