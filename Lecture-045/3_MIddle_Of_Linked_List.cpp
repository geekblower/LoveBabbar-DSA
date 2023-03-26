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

void insertAtMiddle(Node* &head, Node* &tail, int data, int pos) {
    if(pos == 1) {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    while(temp != NULL && pos>2) {
        temp = temp->next;
        pos--;
    }

    if(temp==NULL || pos<=0) {
        cout << "Invalid Position!" << endl;
        return;
    }

    Node *insertNode = new Node(data);
    insertNode->next = temp->next;
    temp->next = insertNode;

    if(insertNode->next == NULL) {
        tail = insertNode;
    }
}

void deletePosition(Node* &head, int pos) {
    Node *temp = head;
    if(pos == 1) {
        head = head->next;
        delete temp;
        return;
    }

    while(temp!=NULL && pos>2) {
        temp = temp->next;
        pos--;
    }

    if(temp==NULL || temp->next==NULL || pos<=0) {
        cout << "Invalid Position!" << endl;
        return;
    }

    Node* target = temp->next;
    temp->next = target->next;
    delete target;
}

void deleteValue(Node* &head, int val) {
    Node* temp = head->next;
    Node* prev = head;
    
    if(head->data == val) {
        head = head->next;
        delete prev;
        return;
    }

    while(temp!=NULL) {
        if(temp->data == val) {
            val = INT_MIN;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if(prev->next==NULL || val!=INT_MIN) {
        cout << "Value Not Found!" << endl;
        return;
    }
    
    prev->next = temp->next;
    delete temp;
}

Node* getMiddle(Node* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }

    Node* fast = head;
    Node* slow = head;

    while(fast!=NULL && fast->next!=NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    Node *head = new Node(1);
    Node *tail = head;

    for(int i=1; i<=5; i++) {
        insertAtTail(tail, pow(2,i));
    }
    printList(head);

    Node* mid = getMiddle(head);
    cout << "Middle Node : " << mid->data << endl;

    return 0;
}