#include<iostream>
#include<vector>
#include <stack>
using namespace std;

void span(vector<int>& price) {
    vector<int> ans;
    stack<int> s;

    for(int i=0; i<price.size(); i++) {
        while (s.size()>0 && price[s.top()] <= price[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans.push_back(i+1);
        } else {
            ans.push_back(i-s.top());
        }

        s.push(i);
    }

    for(int val: ans) {
        cout<<val<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    span(price);
    return 0;
}