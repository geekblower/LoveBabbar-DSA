#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

// Recursive Way
// Node* LCAinBST(Node* root, Node* P, Node* Q) {
//     if(root == NULL) {
//         return NULL;
//     }

//     if(root->data < P->data && root->data < Q->data) {
//         return LCAinBST(root->right, P, Q);
//     }

//     if(root->data > P->data && root->data > Q->data) {
//         return LCAinBST(root->left, P, Q);
//     }

//     return root;
// }

// Iterative Way
Node* LCAinBST(Node* root, Node* P, Node* Q) {
    while(root != NULL) {
        if(root->data < P->data && root->data < Q->data) {
            root = root->right;
        } else if (root->data > P->data && root->data > Q->data) {
            root = root->left;
        } else {
            return root;
        }
    }
}

int main() {
    Node* root = NULL;
    int d1, d2;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << "Enter the two node values : ";
    cin >> d1 >> d2;

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    Node* P = searchNode(root, d1);
    Node* Q = searchNode(root, d2);
    
    Node* AnsNode = LCAinBST(root, P, Q);

    cout << "Lowest Common Anchestor of " << P->data << " & " << Q->data <<" is : ";
    cout << AnsNode->data << endl;

    return 0;
}

// 14 12 28 8 4 10 9 11 19 32 18 17 22 21 24 39 -1