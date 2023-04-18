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

Node* cloneList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        Node* next = temp->next;
        Node* cloneNode = new Node(temp->data);
        temp->next = cloneNode;
        temp = cloneNode->next = next;
    }

    Node *cloneHead = head->next;
    Node* clone = cloneHead;

    temp = head;    
    while(temp != NULL) {
        temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    temp = head;
    while(clone->next != NULL) {
        temp = temp->next = temp->next->next;
        clone = clone->next = clone->next->next;
    }
    
    temp->next = clone->next = NULL;
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