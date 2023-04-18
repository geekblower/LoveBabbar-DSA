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

void printList(Node* head) {
    if(head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    
    cout << "Singly List : ";
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void Sort012(Node* &head) {
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    while(head != NULL) {
        Node* target = new Node(head->data);

        if(target->data == 0) {
            zeroTail = zeroTail->next = target;
        } else if(target->data == 1) {
            oneTail = oneTail->next = target;
        } else {
            twoTail = twoTail->next = target;
        }

        head = head->next;
    }

    if(oneHead->next == NULL) {
        zeroTail->next = twoHead->next;
    } else {
        zeroTail->next = oneHead->next;
    }
    
    oneTail->next = twoHead->next;
    head = zeroHead->next;
}

int main() {
    Node *head = new Node(0);
    Node *tail = head;

    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 0);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);

    printList(head);

    Sort012(head);
    cout << "After sorting : ";
    printList(head);

    return 0;
}