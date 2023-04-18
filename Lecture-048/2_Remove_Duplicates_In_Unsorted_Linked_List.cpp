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

void removeNodes1(Node* &head) {
    if(head == NULL) {
        return;
    }

    Node* curr = head;
    while(curr->next != NULL) {
        Node* prev = curr;
        Node* temp = curr->next;

        while(temp != NULL) {
            if(curr->data == temp->data) {
                Node* target = temp;
                temp = temp->next;
                prev->next = temp;
                delete target;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        
        curr = curr->next;
    }
}


void removeNodes2(Node* &head) {
    if(head == NULL) {
        return;
    }

    map<int, bool> visited;
    Node* temp = head;
    visited[temp->data] = true;

    while(temp->next != NULL) {
        if(visited[temp->next->data] == true) {
            Node* target = temp->next;
            temp->next = target->next;
            delete target;
        } else {
            visited[temp->next->data] = true;
            temp = temp->next;
        }
    }
}

int main() {
    Node *head = new Node(1);
    Node *tail = head;

    insertAtTail(tail, pow(2,2));
    insertAtTail(tail, pow(2,1));
    insertAtTail(tail, pow(2,9));
    insertAtTail(tail, pow(2,4));
    insertAtTail(tail, pow(2,7));
    insertAtTail(tail, pow(2,9));
    insertAtTail(tail, pow(2,2));
    insertAtTail(tail, pow(2,4));
    insertAtTail(tail, pow(2,0));
    insertAtTail(tail, pow(2,2));
    insertAtTail(tail, pow(2,9));
    insertAtTail(tail, pow(2,9));

    printList(head);

    removeNodes1(head);
    printList(head);

    return 0;
}