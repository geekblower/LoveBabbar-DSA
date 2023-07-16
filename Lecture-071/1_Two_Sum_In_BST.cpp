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

bool checkTwoSum(Node* root, int target) {
    if(root == NULL) {
        return false;
    }

    vector<int> arr;
    inOrder(root, arr);

    int i=0, j=arr.size()-1;
    while(i <= j) {
        if(arr[i] + arr[j] == target) {
            return true;
        }

        if(arr[i] + arr[j] > target) {
            j--;
        } else {
            i++;
        }
    }

    return false;
}

int main() {
    Node* root = NULL;
    int target;

    cout << "Enter data to create BST : ";
    takeinput(root);

    cout << "Enter the target value : ";
    cin >> target;

    cout << endl << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);

    bool isSum = checkTwoSum(root, target);
    
    if(isSum) {
        cout << "Sum pair is present in BST!" << endl;
    } else {
        cout << "Sum pair is not present in BST!" << endl;
    }

    return 0;
}

// 14 12 28 8 4 10 9 11 19 32 18 17 22 21 24 39 -1
