#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

void inOrder(Node* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

Node* balanceBST(vector<int>& arr, int start, int end) {
    if(end-start < 0) {
        return NULL;
    }

    int mid = start + (end-start)/2;
    Node* temp = new Node(arr[mid]);

    temp->left = balanceBST(arr, start, mid-1);
    temp->right = balanceBST(arr, mid+1, end);

    return temp;
}

Node* NormalToBalance(Node* &root) {
    if(root == NULL) {
        return NULL;
    }

    vector<int> arr;
    inOrder(root, arr);

    Node* newBST = balanceBST(arr, 0, arr.size()-1);

    return newBST;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "Level Order Traversal of Normal BST : " << endl;
    levelOrderTraversal(root);

    Node* newRoot = NormalToBalance(root);

    cout << endl << "Level Order Traversal of Balanced BST : " << endl;
    levelOrderTraversal(newRoot);

    return 0;
}

// 10 8 12 5 15 2 18 -1
// 5 3 6 4 2 7 8 -1