#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printHead(Node* head) {
    if(head == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }

    cout << "Doubly List by Head : ";
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printTail(Node* tail) {
    if(tail == NULL) {
        cout << "List is Empty!" << endl;
        return;
    }
    
    cout << "Doubly List by Tail : ";
    while(tail != NULL) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* &tail, int data) {
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
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
    insertNode->prev = temp;
    temp->next = insertNode;

    if(insertNode->prev == tail) {
        tail = insertNode;
    } else {
        temp->next->prev = insertNode;
    }
}

void deletePosition(Node* &head, Node* &tail, int pos) {
    Node *temp = head;
    if(pos == 1) {
        head = head->next;
        delete temp;

        if(head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

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

    if(target == tail) {
        tail = tail->prev;
    } else {
        target->next->prev = temp;
    }

    delete target;
}

void deleteValue(Node* &head, Node* &tail, int val) {
    Node* temp = head;
    
    if(head->data == val) {
        head = head->next;
        delete temp;

        if(head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        return;
    }

    while(temp!=NULL) {
        if(temp->data == val) {
            val = INT_MIN;
            break;
        }

        temp = temp->next;
    }

    if(temp==NULL || val!=INT_MIN) {
        cout << "Value Not Found!" << endl;
        return;
    }
    
    temp->prev->next = temp->next;

    if(temp == tail) {
        tail = tail->prev;
    } else {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main() {
    Node *head = new Node(1);
    Node *tail = head;


    for(int i=1; i<=5; i++) {
        insertAtTail(tail, pow(2,i));
        // insertAtHead(head, pow(2,i));
    }

    printHead(head);
    printTail(tail);

    // insertAtMiddle(head, tail, 99, 6);
    //deletePosition(head, tail, 8);
    deleteValue(head, tail, 64);

    printHead(head);
    printTail(tail);

    return 0;
}