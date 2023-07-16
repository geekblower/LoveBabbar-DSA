#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeinput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void preOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderRecursive(root->left);
    preOrderRecursive(root->right);
}

void inOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrderRecursive(root->left);
    cout << root->data << " ";
    inOrderRecursive(root->right);
}

void postOrderRecursive(Node* root) {
    if(root == NULL) {
        return;
    }

    postOrderRecursive(root->left);
    postOrderRecursive(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "InOrder Traversal : ";
    inOrderRecursive(root);

    cout << endl << "PreOrder Traversal : ";
    preOrderRecursive(root);

    cout << endl << "PostOrder Traversal : ";
    postOrderRecursive(root);

    return 0;
}