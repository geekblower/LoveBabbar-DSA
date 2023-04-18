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

Node* mergeList(Node* list1, Node* list2) {
    if(list1==NULL || list2==NULL) {
        return (list1 == NULL) ? list2 : list1;
    }

    Node* prev = list1;
    Node* curr = list1->next;

    while(curr!=NULL && list2!=NULL) {
        if(prev->data <= list2->data && curr->data >= list2->data) {
            prev->next = list2;
            list2 = list2->next;
            prev->next->next = curr;
            prev = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    if(list2 != NULL) {
        prev->next = list2;
    }

    return list1;
}

int main() {
    Node *head1 = new Node(1);
    Node *tail1 = head1;
    
    Node *head2 = new Node(0);
    Node *tail2 = head2;

    for(int i=1; i<5; i++) {
        insertAtTail(tail1, pow(2,i));
    }

    for(int i=1; i<7; i++) {
        insertAtTail(tail2, pow(3,i));
    }
    
    cout << "First List : ";
    printList(head1);

    cout << "Second List : ";
    printList(head2);

    Node* answer = NULL;

    if(head1->data < head2->data) {
        answer = mergeList(head1, head2);
    } else {
        answer = mergeList(head2, head1);
    }

    cout << "Sorted List : ";
    printList(answer);

    return 0;
}