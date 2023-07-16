#include <bits/stdc++.h>
#include "BinaryTree.h"

using namespace std;

bool isIdentical(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }

    if(root1==NULL || root2==NULL) {
        return false;
    }

    bool isLeft = isIdentical(root1->left, root2->left);
    bool isRight = isIdentical(root1->right, root2->right);
    bool value = (root1->data == root2->data);
    
    return isLeft && isRight & value;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    root1 = buildTree(root1);
    root2 = buildTree(root2);

    bool check = isIdentical(root1, root2);

    if(check) {
        cout << endl << "Identical Trees!" << endl;
    } else {
        cout << endl << "Non-Identical Trees!" << endl;
    }

    return 0;
}

/*
    INPUT:
        1 2 -1 -1 3 -1 -1
        1 2 -1 -1 3 -1 -1

        1 3 -1 -1 3 -1 -1
        1 2 -1 -1 3 -1 -1

        1 2 -1 7 -1 -1 3 -1 -1
        1 2 -1 -1 3 -1 -1
*/