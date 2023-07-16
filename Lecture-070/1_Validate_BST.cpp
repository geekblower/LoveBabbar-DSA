#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

bool ValidateBST(Node* root, int min, int max) {
    if(root == NULL) {
        return true;
    }

    if(root->data >= min && root->data <= max) {
        bool left = ValidateBST(root->left, min, root->data);
        bool right = ValidateBST(root->right, root->data, max);

        return (left && right);
    }

    return false;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    if(ValidateBST(root, INT_MIN, INT_MAX)) {
        cout << "YES ! It is a Binary Search Tree.";
    } else {
        cout << "NO ! It is not a Binary Search Tree.";
    }

    return 0;
}