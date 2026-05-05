#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val) {
        data = val;
        next = prev = child = NULL;
    }
};

Node* flatten(Node* head) {
    if(head == NULL) return head; 

    Node* curr = head; 
    while(curr != NULL) { 
        if(curr->child != NULL) { 
            Node* next = curr->next; 
            curr->next = flatten(curr->child); 
            curr->next->prev = curr; 
            
            curr->child = NULL; 
            while (curr->next != NULL) { 
                curr = curr->next; 
            } 
            
            if(next != NULL) { 
                curr->next = next; 
                next->prev = curr; 
            } 
        } 
        
        curr = curr->next; 
    } 
    
    return head; 
}

void printList(Node* head) { 
    Node* temp = head; 
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl; 
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    Node* child1 = new Node(7);
    child1->next = new Node(8);
    child1->next->prev = child1;

    child1->next->next = new Node(9);
    child1->next->next->prev = child1->next;

    head->next->next->child = child1;

    Node* child2 = new Node(11);
    child2->next = new Node(12);
    child2->next->prev = child2;

    child1->next->child = child2;

    cout << "Flattened list: ";
    head = flatten(head);
    printList(head);
    return 0;
}