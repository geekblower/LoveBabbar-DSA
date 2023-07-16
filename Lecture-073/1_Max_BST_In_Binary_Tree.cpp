#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

class Info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;

        Info() {
            this->maxi = INT_MIN;
            this->mini = INT_MAX;
            this->isBST = true;
            this->size = 0;
        }

        Info(int min, int max, bool isBST, int size) {
            this->maxi = max;
            this->mini = min;
            this->isBST = isBST;
            this->size = size;
        }
};

Info* MaxBST(Node* root, int &answer) {
    if(root == NULL) {
        Info* temp = new Info();
        return temp;
    }

    Info* left = MaxBST(root->left, answer);
    Info* right = MaxBST(root->right, answer);

    Info* currNode = new Info();

    currNode->size = left->size + right->size + 1;
    currNode->maxi = max(root->data, right->maxi);
    currNode->mini = min(root->data, left->mini);

    if(left->isBST && right->isBST && (root->data > left->maxi) && (root->data < right->mini)) {
        currNode->isBST = true;
    } else {
        currNode->isBST = false;
    }

    if(currNode->isBST) {
        answer = max(answer, currNode->size);
    }

    return currNode;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create a tree : ";
    root = buildBinaryTree(root);
    
    int answer = INT_MIN;
    Info* solve = MaxBST(root, answer);

    cout << endl << "Max BST : " << answer;
    
    return 0;
}

// 50 40 60 70 -1
// 55 45 35 65 47 -1