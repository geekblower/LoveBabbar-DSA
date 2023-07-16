#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        int row, col;

        Node(int data, int row, int col) {
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare {
    public:
        bool operator () (Node* a, Node* b) {
            return a->data > b->data;
        }
};

vector<int> mergeSortedArrays(vector<vector<int> > kArrays, int K) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Step 1 : Insert all first elements in minHeap
    for(int row=0; row<K; row++) {
        Node* temp = new Node(kArrays[row][0], row, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // Step 2 : Comparing each node and moving further in the array
    while(minHeap.size() > 0) {
        Node* temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();

        int row = temp->row;
        int col = temp->col;

        if(col+1 < kArrays[row].size()) {
            Node* next = new Node(kArrays[row][col+1], row, col+1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main() {
    vector< vector<int> > kArrays;
    int K;

    cout << "Enter the value of K : ";
    cin >> K;

    for(int i=0; i<K; i++) {
        vector<int> curr;

        cout << "Enter the elements of array (-1 to stop) : ";
        int temp;
        cin >> temp;
        do {
            curr.push_back(temp);
            cin >> temp;
        } while(temp != -1);

        kArrays.push_back(curr);
    }
    
    vector<int> mergedArray = mergeSortedArrays(kArrays, K);

    cout << "Merged array : ";
    for(auto i : mergedArray) {
        cout << i << " ";
    }

    return 0;
}