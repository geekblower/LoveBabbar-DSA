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

int smallestRange(vector<vector<int> > kArrays, int K, int N) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    int mini = INT_MAX, maxi = INT_MIN;


    // Step 1 : Creating a Min Heap for starting element of each list and tracking mini/maxi value of each list
    for(int row=0; row<K; row++) {
        int element = kArrays[row][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new Node(element, row, 0));
    }

    int start = mini, end = maxi;

    // Step 2 : process ranges
    while(!minHeap.empty()) {

        // fetching minimum element
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // range or answer updation
        if(maxi - mini < end - start) {
            start = mini;
            end = maxi;
        }

        // checking whether next element exists or not
        if(temp->col < N) {
            maxi = max(maxi, kArrays[temp->row][temp->col + 1]);
            minHeap.push(new Node(kArrays[temp->row][temp->col + 1], temp->row, temp->col + 1));
        } else {
            break;
        }
    }

    return (end - start) + 1;
}

int main() {
    vector< vector<int> > kArrays;
    int K, N;

    cout << "Enter the value of K : ";
    cin >> K;

    cout << "Enter the size of each array : ";
    cin >> N;

    for(int i=0; i<K; i++) {
        vector<int> curr(N);

        cout << "Enter the elements of array : ";
        for(int j=0; j<N; j++) {
            cin >> curr[j];
        }

        kArrays.push_back(curr);
    }
    
    int range = smallestRange(kArrays, K, N);

    cout << "Smallest range in the given sorted lists : " << range << endl;

    return 0;
}