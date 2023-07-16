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
    cout << "Enter the elements of BST (-1 to stop) : ";

    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* FrontNode = Q.front();
        Q.pop();

        if(FrontNode == NULL) {
            cout << endl;
            
            if(!Q.empty()) {
                Q.push(NULL);
            }
        } else {
            cout << FrontNode->data << " ";

            if(FrontNode->left) {
                Q.push(FrontNode->left);
            }

            if(FrontNode->right) {
                Q.push(FrontNode->right);
            }
        }
    }
}

Node* searchNode(Node* root, int key) {
    return (root == NULL || root->data == key) ? root : ((root->data > key) ? searchNode(root->left, key) : searchNode(root->right, key));
}