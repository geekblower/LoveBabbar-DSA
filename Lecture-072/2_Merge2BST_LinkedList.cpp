#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

void flattenBST(Node* root, Node* &head) {
    if(root == NULL) {
        return;
    }

    flattenBST(root->right, head);
    root->right = head;
    
    if(head != NULL) {
        head->left = root;
    }

    head = root;
    flattenBST(root->left, head);
}

Node* mergeLinkedhead(Node* head1, Node* head2) {
    Node* head = NULL;
    Node* tail = NULL;

    cout << "\nBEFORE FIRST WHILE\n";
    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head == NULL) {
                head = tail = head1;
                head1 = head1->right;
            } else {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        } else {
            if(head == NULL) {
                head = tail = head2;
                head2 = head2->right;
            } else {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    cout << "\nAFTER FIRST WHILE\n";
    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

Node* LL_2_BST(Node* head, int n) {
    if(n <= 0 || head == NULL) {
        return NULL;
    }

    int temp = n/2;
    Node* root = head;
    while(temp--) {
        root = root->right;
    }

    root->left = LL_2_BST(head, n/2);
    root->right = LL_2_BST(root->right, n-n/2-1);
    return root;

    // Node* left = LL_2_BST(head, n/2);

    // Node* root = head;
    // root->left = left;
    // head = head->right;
    // root->right = LL_2_BST(head, n-n/2-1);

    // return root;
}

Node* MergeBST(Node* root1, Node* root2) {
    // Step 1 : Convert BST into DLL
    Node* head1 = NULL;
    Node* head2 = NULL;

    flattenBST(root1, head1);
    flattenBST(root2, head2);

    head1->left = NULL;
    head2->left = NULL;

    // Merge Sorted Linked List
    Node* list = mergeLinkedhead(head1, head2);

    // Convert List into BST
    Node* result = LL_2_BST(list, countNodes(list));

    return result;
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    int target;

    cout << "Enter data to create BST 1 : ";
    takeinput(root1);
    
    cout << "Enter data to create BST 2 : ";
    takeinput(root2);

    cout << endl << "Level Order Traversal of BST 1 : " << endl;
    levelOrderTraversal(root1);
    
    cout << endl << "Level Order Traversal of BST 2 : " << endl;
    levelOrderTraversal(root2);
    
    Node* result = MergeBST(root1, root2);

    cout << endl << "Level Order Traversal of merged BST : " << endl;
    levelOrderTraversal(result);
    
    return 0;
}

// 50 40 60 70 -1
// 55 45 35 65 47 -1