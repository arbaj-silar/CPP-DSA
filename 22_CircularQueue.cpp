#include<iostream>
#include<vector>
using namespace std;

class CicularQueue {
    int* arr;
    int currSize, cap;
    int f=0, r=-1;

public:
    CicularQueue(int size) {
        cap = size;
        arr = new int(cap);
        f = 0, r = -1;
    }

    void push(int data) {
        if(currSize == cap) {
            cout<<"CQ is Full\n";
            return;
        }

        r = (r+1)%cap;
        arr[r] = data;
        currSize++;
    }

    void pop() {
        if(currSize == cap) {
            cout<<"CQ is Full\n";
            return;
        }

        f = (f+1)%cap;
        currSize--;
    }

    int front() {
        if(currSize == cap) {
            cout<<"CQ is Full\n";
            return -1;
        }

        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }

    void printArr() {
        for(int i =0; i<cap; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    CicularQueue cq(3);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);

    cq.printArr();
    return 0;
}
