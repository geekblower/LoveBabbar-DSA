#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

int getHeight(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int h1 = getHeight(root->left);
    int h2 = getHeight(root->right);

    return max(h1, h2) + 1;
}

int getDiameter(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int d1 = getDiameter(root->left);
    int d2 = getDiameter(root->right);
    int d3 = getHeight(root->left) + getHeight(root->right) + 1;

    return max(d1, max(d2, d3));
}

pair<int, int> getDiameterOptimised(Node* root) {
    if(root == NULL) {
        return {0,0};
    }

    pair<int, int> d1 = getDiameterOptimised(root->left);
    pair<int, int> d2 = getDiameterOptimised(root->right);
    pair<int, int> ans;

    ans.second = max(d1.second, d2.second) + 1;

    int opt1 = d1.first;
    int opt2 = d2.first;
    int opt3 = d1.second + d2.second + 1;

    ans.first = max(opt1, max(opt2, opt3));

    return ans;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    // int Diameter = getDiameter(root);
    pair<int, int> Diameter = getDiameterOptimised(root);

    cout << endl << "Diameter of the tree is : " << Diameter.first << endl;

    return 0;
}

/*
    INPUT:
        3 4 -1 -1 6 -1 -1
        5 4 2 -1 6 -1 -1 7 -1 8 -1 9 -1 -1 10 -1 -1
        8 2 4 -1 -1 6 2 -1 -1 5 -1 -1 5 -1 9 -1 6 4 2 -1 -1 3 -1 -1 7 -1 -1
*/