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

void levelOrderTraversal(Node* root) {
    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {
        Node* temp = Q.front();
        Q.pop();

        if(temp == NULL) {
            cout << endl;

            if(!Q.empty()) {
                Q.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            if(temp->left) {
                Q.push(temp->left);
            }

            if(temp->right) {
                Q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

Node* BuildLevelOrder(Node* root) {
    queue<Node*> Q;
    int data;
    cout << "Enter data : ";
    cin >> data;
    root = new Node(data);
    Q.push(root);

    while(!Q.empty()) {
        Node* temp = Q.front();
        Q.pop();

        cout << "Enter leftnode of " << temp->data << " : ";
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp->left = new Node(leftData);
            Q.push(temp->left);
        }

        cout << "Enter rightnode of " << temp->data << " : ";
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp->right = new Node(rightData);
            Q.push(temp->right);
        }
    }

    return root;
}

int main() {
    Node* root = NULL;

    // Creating a tree
    root = BuildLevelOrder(root);

    cout << "\nLevel Order Traversal : " << endl;
    levelOrderTraversal(root);

    // cout << "\nIn Order Traversal : " << endl;
    // inOrderTraversal(root);
    
    // cout << "\nPre Order Traversal : " << endl;
    // preOrderTraversal(root);
    
    // cout << "\nPost Order Traversal : " << endl;
    // postOrderTraversal(root);

    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1