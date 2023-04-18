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

int getLength(Node* tail) {
    if(tail == NULL) {
        return 0;
    }

    int count = 1;
    Node* temp = tail->next;

    while(temp != tail) {
        count++;
        temp = temp->next;
    }

    return count;
}

pair<Node*, Node*> splitList(Node* tail) {
    Node* tail1 = tail;
    Node* tail2 = NULL;
    int len = (getLength(tail) + 1) / 2;

    Node* temp = tail;
    while(len > 1) {
        temp = temp->next;
        len--;
    }

    tail2 = temp->next;
    temp->next = tail;
    temp = tail2;

    while(temp->next != tail) {
        temp = temp->next;
    }

    temp->next = tail2;

    return {tail1, tail2};
}

int main() {
    Node *tail = NULL;

    insertion(tail, pow(2,4), 2);
    insertion(tail, pow(2,3), 16);
    insertion(tail, pow(2,5), 8);
    insertion(tail, pow(2,2), 16);
    insertion(tail, pow(2,0), 8);

    printList(tail);

    pair<Node*, Node*> solution;
    solution = splitList(tail);

    printList(solution.first);
    printList(solution.second);

    return 0;
}