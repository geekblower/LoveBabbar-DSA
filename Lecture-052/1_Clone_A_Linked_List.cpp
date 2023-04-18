#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *random;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* head) {
    if(head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    
    while(head != NULL) {
        cout << "[" << head->data << "," << head->random->data << "] ";
        // cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);    
    
    if(tail == NULL) {
        head = tail = temp;
    } else {
        tail = tail->next = temp;
    }
}

Node* cloneList(Node* head) {
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;
    map<Node*, Node*> mapping;

    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        mapping[temp] = cloneTail;
        temp = temp->next;
    }

    temp = head;
    Node* clone = cloneHead;

    while(clone != NULL) {
        clone->random = mapping[temp->random];
        temp = temp->next;
        clone = clone->next;
    }

    return cloneHead;
}

int main() {
    Node *head = new Node(5);;

    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    cout << "Original List : ";
    printList(head);

    Node *clone = cloneList(head);

    cout << "Clone List : ";
    printList(clone);

    return 0;
}