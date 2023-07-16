#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

void traverseLeft(Node* root, vector<int> &answer) {
    if(root == NULL) {
        return;
    }
    
    // For Leaf Node
    if(root->left == NULL && root->right == NULL) {
        return;
    }

    answer.push_back(root->data);

    if(root->left) {
        traverseLeft(root->left, answer);
    } else {
        traverseLeft(root->right, answer);
    }
}

void traverseLeaf(Node* root, vector<int> &answer) {
    if(root == NULL) {
        return;
    }
    
    // For Leaf Node
    if(root->left == NULL && root->right == NULL) {
        answer.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, answer);
    traverseLeaf(root->right, answer);
}

void traverseRight(Node* root, vector<int> &answer) {
    if(root == NULL) {
        return;
    }
    
    // For Leaf Node
    if(root->left == NULL && root->right == NULL) {
        return;
    }

    if(root->right) {
        traverseRight(root->right, answer);
    } else {
        traverseRight(root->left, answer);
    }

    answer.push_back(root->data);

}

vector<int> Boundary(Node* root) {
    if(root == NULL) {
        return {};
    }

    vector<int> answer;
    answer.push_back(root->data);

    // Printing Left Part
    traverseLeft(root->left, answer);

    // Printing Leaf Nodes from left subtree
    traverseLeaf(root->left, answer);
    
    // Printing Leaf Nodes from right subtree
    traverseLeaf(root->right, answer);

    // Printing Right Part
    traverseRight(root->right, answer);
    
    return answer;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    vector<int> answer = Boundary(root);

    cout << endl << "Boundary Traversal : ";
    for(auto i : answer) {
        cout << i << " ";
    }

    return 0;
}

/*
    INPUT:
        1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
        7 9 8 10 -1 -1 9 -1 -1 8 -1 -1 7 6 -1 -1 -1
*/