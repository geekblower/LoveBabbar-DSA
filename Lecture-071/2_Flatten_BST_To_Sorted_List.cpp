#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

void inOrder(Node* root, vector<Node*>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root);
    inOrder(root->right, ans);
}


void flattenBST(Node* &root) {
    if(root == NULL) {
        return;
    }

    vector<Node*> arr;
    inOrder(root, arr);

    for(int i=0; i<arr.size()-1; i++) {
        arr[i]->left = NULL;
        arr[i]->right = arr[i+1];
    }

    arr[arr.size()-1]->left = NULL;
    arr[arr.size()-1]->right = NULL;

    root = arr[0];
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    flattenBST(root);

    Node* temp = root;
    cout << "Flatten BST : ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    return 0;
}

// 14 12 28 8 4 10 9 11 19 32 18 17 22 21 24 39 -1