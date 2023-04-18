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

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node* addLL(Node *head1, Node *head2) {
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* answer = NULL;
    int carry = 0;

    while(temp1!=NULL || temp2!=NULL || carry!=0) {
        int val1 = 0;
        if(temp1 != NULL) {
            val1 = temp1->data;
        }

        int val2 = 0;
        if(temp2 != NULL) {
            val2 = temp2->data;
        }

        int sum = val1 + val2 + carry;
        insertAtHead(answer, sum%10);
        carry = sum / 10;

        if(temp1 != NULL) {
            temp1 = temp1->next;
        }

        if(temp2 != NULL) {
            temp2 = temp2->next;
        }
    }
    
    head1 = reverse(head1);
    head2 = reverse(head2);

    return answer;
}

int main() {
    Node *head1 = NULL;
    Node *head2 = NULL;

    insertAtHead(head1, 5);
    insertAtHead(head1, 4);

    insertAtHead(head2, 5);
    insertAtHead(head2, 9);
    insertAtHead(head2, 9);

    Node *sum = addLL(head1, head2);

    cout << "List 1 : ";
    printList(head1);
    cout << "List 2 : ";
    printList(head2);
    cout << "Sum : ";
    printList(sum);

    return 0;
}