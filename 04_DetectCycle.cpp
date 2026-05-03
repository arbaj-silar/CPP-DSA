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

    void createCycle(int pos) {
        if (head == NULL) return;
        
        Node* temp = head;
        Node* cycleNode = NULL;
        int count = 0;
        
        while (temp->next != NULL) {
            if (count == pos) {
                cycleNode = temp;
            }
            temp = temp->next;
            count++;
        }
        
        // temp is now at tail
        if (cycleNode != NULL) {
            temp->next = cycleNode;
        }
    }
    
    void detectCycle() {
        Node* slow = head;
        Node* fast = head;
        bool isCycle = false;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                isCycle = true;
                break;
            }
        }

        if(isCycle) {
            cout<<"true\n";
        } else {
            cout<<"false\n";
        }
        
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        cout<<"Start point of Cycle: "<<slow->data<<endl;
    }

    int it = 0;
    void printLL() {
        Node* temp = head;

        while(temp != NULL) {
            if(it == 15) break;
            cout<<temp->data<<"->";
            temp = temp->next;
            it++;
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
    ll.createCycle(4);
    
    ll.printLL();
    ll.detectCycle();
    return 0;
}