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

int minVal(Node* root) {
    if(root == NULL) {
        return -1;
    }

    Node* temp = root;
    while(temp->left) {
        temp = temp->left;
    }

    return temp->data;
}

int maxVal(Node* root) {
    if(root == NULL) {
        return -1;
    }
    
    Node* temp = root;
    while(temp->right) {
        temp = temp->right;
    }

    return temp->data;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << endl << "Minimum Value : " << minVal(root);
    cout << endl << "Maximum Value : " << maxVal(root);

    return 0;
}