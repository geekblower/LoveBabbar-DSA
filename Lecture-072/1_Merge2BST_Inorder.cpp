#include <bits/stdc++.h>
#include "BST.h"
using namespace std;

void inOrder(Node* root, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

vector<int> mergeArrays(vector<int> arr1, vector<int> arr2) {
    if(arr1.size() == 0 || arr2.size() == 0) {
        return (arr1.size()) ? arr1 : arr2;
    }

    int i=0, j=0;
    vector<int> solution;

    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] < arr2[j]) {
            solution.push_back(arr1[i++]);
        } else {
            solution.push_back(arr2[j++]);
        }
    }
    
    while(i<arr1.size()) {
        solution.push_back(arr1[i++]);
    }
    
    while(j<arr2.size()) {
        solution.push_back(arr2[j++]);
    }

    return solution;
}

Node* createBST(vector<int> &arr, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = start + (end-start)/2;
    Node* temp = new Node(arr[mid]);

    temp->left = createBST(arr, start, mid-1);
    temp->right = createBST(arr, mid+1, end);

    return temp;
}

Node* MergeBST(Node* root1, Node* root2) {
    vector<int> arr1;
    vector<int> arr2;

    inOrder(root1, arr1);
    inOrder(root2, arr2);

    vector<int> resultArray = mergeArrays(arr1, arr2);
    Node* answer = createBST(resultArray, 0, resultArray.size()-1);

    cout << endl << "Level Order Traversal of merged BST (infunc) : " << endl;
    levelOrderTraversal(answer);
    return answer;
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