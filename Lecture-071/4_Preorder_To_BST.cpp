#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

// void inOrder(Node* root, vector<int>& ans) {
//     if(root == NULL) {
//         return;
//     }

//     inOrder(root->left, ans);
//     ans.push_back(root->data);
//     inOrder(root->right, ans);
// }

// Node* balanceBST(vector<int>& arr, int start, int end) {
//     if(end-start < 0) {
//         return NULL;
//     }

//     int mid = start + (end-start)/2;
//     Node* temp = new Node(arr[mid]);

//     temp->left = balanceBST(arr, start, mid-1);
//     temp->right = balanceBST(arr, mid+1, end);

//     return temp;
// }

Node* createPreorder(vector<int> &inorder, int &index, int min, int max) {
    if(index >= inorder.size()) {
        return NULL;
    }

    int data = inorder[index];

    if(data < min || data > max) {
        return NULL;
    }

    Node* temp = new Node(data);
    index++;

    temp->left = createPreorder(inorder, index, min, data);
    temp->right = createPreorder(inorder, index, data, max);

    return temp;
}

int main() {
    Node* root = NULL;
    vector<int> preorder;
    int index = 0;

    cout << "Enter elements of preorder traversal (-1 to stop) : ";
    int temp = -1;
    do {
        cin >> temp;
        preorder.push_back(temp);
    } while(temp != -1);

    root = createPreorder(preorder, index, INT_MIN, INT_MAX);

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    return 0;
}

// 20 10 5 15 13 35 30 42 -1
// 5 3 6 4 2 7 8 -1