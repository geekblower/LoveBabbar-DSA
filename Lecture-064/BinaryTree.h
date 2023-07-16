#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(Node* root) {
    int data;
    cout << "Enter the data : ";
    cin >> data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "LEFT of " << data << " : ";
    root->left = buildTree(root->left);
    
    cout << "RIGHT of " << data << " : ";
    root->right = buildTree(root->right);

    return root;
}