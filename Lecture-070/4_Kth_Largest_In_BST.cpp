#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

int kthLargest(Node* root, int &index, int K) {
    if(root == NULL) {
        return -1;
    }

    // Reverse Inorder Traversal
    int right = kthLargest(root->right, index, K);
    if(right != -1) {
        return right;
    }

    index++;
    if(index == K) {
        return root->data;
    }

    return kthLargest(root->left, index, K);
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
    ans = kthLargest(root, index, K);

    cout << "Required answer = " << ans << endl;
    return 0;
}
