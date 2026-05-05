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

Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    int count = 0;

    while(count<k) {
        if(!temp) {
            return head;
        }

        temp = temp->next;
        count++;
    }

    Node* prevNode = reverseKGroup(temp, k);

    temp = head; count = 0;
    while (count<k) {
        Node* next = temp->next;
        temp->next = prevNode;

        prevNode = temp;
        temp = next;
        count++;
    }
    
    return prevNode;
}

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    Node* rev = reverseKGroup(ll.head, 3);

    printList(rev);
    return 0;
}