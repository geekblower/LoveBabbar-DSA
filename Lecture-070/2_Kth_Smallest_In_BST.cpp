#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int kthSmallest(Node* root, int &index, int K) {
    if(root == NULL) {
        return -1;
    }

    int left = kthSmallest(root->left, index, K);

    if(left != -1) {
        return left;
    }

    index++;
    if(index == K) {
        return root->data;
    }

    return kthSmallest(root->right, index, K);
}

int main() {
    Node* root = NULL;
    int K, ans;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << "Enter the value of K : ";
    cin >> K;

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    int index = 0;
    ans = kthSmallest(root, index, K);

    cout << "Required answer = " << ans << endl;
    return 0;
}