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

bool SearchBST(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key > root->data) {
        return SearchBST(root->right, key);
    } else {
        return SearchBST(root->left, key);
    }
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    int key;
    cout << "Enter the key to search : ";
    cin >> key;

    bool found = SearchBST(root, key);
    
    if(found) {
        cout << "Key present in BST!" << endl;
    } else {
        cout << "Key absent in BST!" << endl;
    }

    return 0;
}