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

void printList(Node* head) { 
    Node* temp = head; 
    while (temp) {
        cout << temp->data << "->";
        temp = temp->next;
    } cout << "NULL" << endl; 
}

Node* swapNode(Node* head) {
    if(!head || !head->next) {
        return head;
    }

    Node* first = head;
    Node* sec = head->next;
    Node* prev = NULL;

    while(first && sec) {
        Node* third = sec->next;

        sec->next = first;
        first->next = third;

        if(prev) {
            prev->next = sec;
        } else {
            head = sec;
        }

        prev = first;
        first = third;
        if(third) {
            sec = third->next; 
        } else {
            sec = NULL;
        }
    }

    return head;
}

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    Node* head = swapNode(ll.head);
    printList(head);
    return 0;
}