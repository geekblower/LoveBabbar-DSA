#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

pair<int, int> predecessorSuccessor(Node* root, int key) {
    Node* KeyNode = root;
    int pred = -1;
    int succ = -1;
    
    while(KeyNode->data != key) {
        if(KeyNode->data > key) {
            succ = KeyNode->data;
            KeyNode = KeyNode->left;
        } else {
            pred = KeyNode->data;
            KeyNode = KeyNode->right;
        }
    }

    // Prdecessor
    Node* leftTree = KeyNode->left;
    while(leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Successor
    Node* rightTree = KeyNode->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}

int main() {
    Node* root = NULL;
    int key;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << "Enter the value of key element : ";
    cin >> key;

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    int index = 0;
    pair<int, int> ans = predecessorSuccessor(root, key);

    cout << "Predecessor : " << ans.first << endl;
    cout << "Successor   : " << ans.second << endl;
    return 0;
}

// 9 6 2 8 11 19 7 12 25 -1
