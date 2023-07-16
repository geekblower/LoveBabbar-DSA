#include <bits/stdc++.h>
using namespace std;

class List {
    public:
        int data;
        List* next;

        List(int data) {
            this->data = data;
            this->next = NULL;
        }
};

void insert(List* &head, List* &tail, int val) {
    List* temp = new List(val);
    if(head == NULL) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

class compare {
    public:
        bool operator () (List* a, List* b) {
            return a->data > b->data;
        }
};

List* mergeSortedLists(vector<List* > kLists) {
    priority_queue<List*, vector<List*>, compare> minHeap;
    int K = kLists.size();

    // Empty list
    if(K == 0) {
        return NULL;
    }

    // Step 1 : Creating a Min Heap
    for(int i=0; i<K; i++) {
        if(kLists[i] != NULL) {
            minHeap.push(kLists[i]);
        }
    }

    List* head = NULL;
    List* tail = NULL;

    // Step 2 : Comparing next nodes
    while(minHeap.size() > 0) {
        List* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL) {
            minHeap.push(top->next);
        }

        if(head == NULL) {
            head = tail = top;
        } else {
            tail->next = top;
            tail = top;
        }
    }

    return head;
}

int main() {
    vector<List*> kLists;
    int K;

    cout << "Enter the value of K : ";
    cin >> K;

    for(int i=0; i<K; i++) {
        List* head = NULL;
        List* tail = NULL;
        
        cout << "Enter the values of list (-1 to stop) : ";
        int val;
        cin >> val;
        do {
            insert(head, tail, val);
            cin >> val;
        } while(val != -1);

        kLists.push_back(head);
    }

    List* head = mergeSortedLists(kLists);

    List* temp = head;
    cout << "Merged List : ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
