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
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
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

    void pop_front() {
        if(head == NULL) {
            cout<<"LL is Empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        
        delete temp;
    }

    void pop_back() {
        if(head == NULL) {
            cout<<"LL is Empty"<<endl;
            return;
        }     

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp; 
    }

    void insert(int val, int pos) {
        if(pos < 0) {
            cout<<"Invalid Position"<<endl;
            return;
        }
        if(pos == 0) {
            push_front(val);
            return;
        }
        
        Node* temp = head;
        for(int i=0; i<pos-1; i++) {
            if(temp == NULL) {
                cout<<"Invalid position\n";
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int key) {
        Node* temp = head;
        int pos = 0;

        while (temp != NULL) {
            if(temp->data == key) {
                return pos;
            }

            temp = temp->next;
            pos++;
        }

        return -1;        
    }

    void middle() {
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<"Middle of List: "<<slow->data<<endl;
    }

    void printLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    List ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(6);
    
    ll.printLL();
    ll.middle();
    
    return 0;
}