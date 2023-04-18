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
    Node* temp = head;
    int zero=0, one=0, two=0;

    while(temp != NULL) {
        switch(temp->data) {
            case 0:
                zero++;
                break;
            case 1:
                one++;
                break;
            default:
                two++;
        }

        temp = temp->next;
    }

    temp = head;

    while(zero--) {
        temp->data = 0;
        temp = temp->next;
    }

    while(one--) {
        temp->data = 1;
        temp = temp->next;
    }

    while(two--) {
        temp->data = 2;
        temp = temp->next;
    }
}

int main() {
    Node *head = new Node(1);
    Node *tail = head;

    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 0);

    printList(head);

    Sort012(head);
    cout << "After sorting : ";
    printList(head);

    return 0;
}