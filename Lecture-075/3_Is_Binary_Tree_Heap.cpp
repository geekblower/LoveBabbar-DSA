#include <bits/stdc++.h>
#include "Tree.h"

using namespace std;

int countNodes(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return left + right + 1;
}

bool isCBT(Node* root, int index, int cnt) {
    if(root == NULL) {
        return true;
    }

    if(index > cnt) {
        return false;
    }

    bool left = isCBT(root->left, 2*index + 1, cnt);
    bool right = isCBT(root->right, 2*index + 2, cnt);

    return left && right;
}

bool isMaxOrder(Node* root) {
    if(root == NULL) {
        return true;
    }

    if(root->left == NULL && root->right == NULL) {
        return true;
    }

    if(root->right == NULL) {
        return (root->data) > (root->left->data);
    }

    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);
    bool curr = (root->data > root->left->data) && (root->data > root->right->data);

    return left && right && curr;
}

bool isMinOrder(Node* root) {
    if(root == NULL) {
        return true;
    }

    if(root->left == NULL && root->right == NULL) {
        return true;
    }

    if(root->right == NULL) {
        return (root->data) < (root->left->data);
    }

    bool left = isMinOrder(root->left);
    bool right = isMinOrder(root->right);
    bool curr = (root->data < root->left->data) && (root->data < root->right->data);

    return left && right && curr;
}

bool checkMaxHeap(Node* root) {
    return isCBT(root, 0, countNodes(root)) && isMaxOrder(root);
}

bool checkMinHeap(Node* root) {
    return isCBT(root, 0, countNodes(root)) && isMaxOrder(root);
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    int isMaxHeapOrder = checkMaxHeap(root);
    int isMinHeapOrder = checkMinHeap(root);

    if(isMaxHeapOrder){
        cout << "Given Binary Tree is a Max Heap!" << endl;
    } else if(isMinHeapOrder) {
        cout << "Given Binary Tree is a Min Heap!" << endl;
    } else {
        cout << "Given Binary Tree is not a Heap!" << endl;
    }

    return 0;
}

/*
    40 20 10 -1 -1 15 -1 -1 25 -1 -1
    35 24 15 6 -1 -1 -1 11 -1 -1 29 -1 -1
    12 44 -1 -1 -1
    42 45 12 -1 -1 9 -1 -1 39 6 -1 -1 12 -1 -1
    13 14 16 -1 -1 17 -1 -1 15 -1 19 -1 -1
    20 25 27 -1 -1 29 -1 -1 -1
    40 42 49 -1 -1 -1 47 -1 -1
    34 77 140 -1 -1 90 -1 -1 97 100 -1 -1 120 -1 -1
    92 -1 -1
    42 40 35 -1 -1 -1 -1    
*/