#include<iostream>
#include <unordered_map>
using namespace std;

class Node {

public:
    int data;
    Node* next;
    Node* random;

    Node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    unordered_map<Node*, Node*> m;

    Node* newHead = new Node(head->data);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;
    m[head] = newHead;

    while(oldTemp != NULL) {
        Node* copyNode = new Node(oldTemp->data);
        m[oldTemp] = copyNode;
        newTemp->next = copyNode;

        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    oldTemp = head; newTemp = newHead;
    while(oldTemp != NULL) {
        newTemp->random = m[oldTemp->random];
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newHead;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << "Data: " << head->data;

        if(head->random)
            cout << ", Random: " << head->random->data;
        else
            cout << ", Random: NULL";

        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->random = head->next->next;  
    head->next->random = head;        
    head->next->next->random = head->next; 

    Node* copyHead = copyRandomList(head);
    printList(copyHead);
    return 0;
}