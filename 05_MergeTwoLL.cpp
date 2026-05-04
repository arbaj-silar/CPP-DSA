#include<iostream>
using namespace std;

class Node {

public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = tail = NULL;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

Node* mergeTwoLists(Node* head1, Node* head2) {
    if(head1 == NULL || head2 == NULL) {
        return head1 == NULL? head2: head1;
    }

    if(head1->data <= head2->data) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

int main() {
    List head1;
    head1.push_back(1);
    head1.push_back(3);
    head1.push_back(4);

    List head2;
    head2.push_back(2);
    head2.push_back(3);
    head2.push_back(5);

    Node* merge = mergeTwoLists(head1.head, head2.head);

    Node* temp = merge;
    while(temp != NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<"NULL"<<endl;
    return 0;
}