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

bool isBalanced(Node* root) {
    if(root == NULL) {
        return true;
    }

    bool isLeft = isBalanced(root->left);
    bool isRight = isBalanced(root->right);

    bool diff = abs(getHeight(root->left) - getHeight(root->right)) <= 1;

    return isLeft && isRight && diff;
}

pair<bool, int> isBalancedOptimised(Node* root) {
    if(root == NULL) {
        return {true, 0};
    }

    pair<bool, int> left = isBalancedOptimised(root->left);
    pair<bool, int> right = isBalancedOptimised(root->right);

    bool isLeft = left.first;
    bool isRight = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.first = isLeft && isRight && diff;
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);

    // bool check = isBalanced(root);
    bool check = isBalancedOptimised(root).first;

    if(check) {
        cout << endl << "Balanced Tree!" << endl;
    } else {
        cout << endl << "Not a balanced tree!" << endl;
    }

    return 0;
}

/*
    INPUT:
        1 10 5 -1 -1 -1 39 -1 -1
        1 10 5 -1 -1 -1 -1
*/