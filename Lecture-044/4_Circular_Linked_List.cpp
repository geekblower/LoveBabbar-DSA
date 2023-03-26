#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* tail) {
    if(tail == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }

    Node* temp = tail;
    cout << "Circular List : ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);
    
    cout << endl;
}

void insertion(Node* &tail, int data, int target) {
    Node *insertNode = new Node(data);

    if(tail == NULL) {
        tail = insertNode;
        insertNode->next = tail;
        return;
    }

    Node* curr = tail;

    while(curr->data != target) {
        curr = curr->next;
    }

    insertNode->next = curr->next;
    curr->next = insertNode;
}

void deletion(Node* &tail, int val) {
    if(tail == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = tail->next;

    while(curr->data != val) {
        prev = curr;
        curr = curr->next;

        if(curr == tail && curr->data != val) {
            cout << "Element Not Found!" << endl;
            return;
        }
    }

    prev->next = curr->next;
    curr->next = NULL;

    if(curr == tail) {
        tail = prev;
    }

    delete curr;
}

int main() {
    Node *tail = NULL;

    insertion(tail, pow(2,4), 2);
    insertion(tail, pow(2,3), 16);
    insertion(tail, pow(2,5), 8);
    insertion(tail, pow(2,2), 16);

    printList(tail);

    deletion(tail, 64);
    printList(tail);

    return 0;
}