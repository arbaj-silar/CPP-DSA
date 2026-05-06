#include<iostream>
#include<vector>
#include <stack>
#include<unordered_map>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;

    for(int i=arr.size()-1; i>=0; i--) {
        while(s.size() > 0 && s.top() <= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = arr[i];
        }

        s.push(arr[i]);
    }

    return ans;
}

vector<int> nextGreater(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    unordered_map<int, int> m;
    stack<int> s;

    for(int i=n-1; i>=0; i--) {
        while(s.size() > 0 && s.top() <= nums2[i]) {
            s.pop();
        }

        if(s.empty()) {
            m[nums2[i]] = -1;
        } else {
            m[nums2[i]] = nums2[i];
        }

        s.push(nums2[i]);
    }

    vector<int> ans;
    for(int i=0; i<nums1.size(); i++) {
        ans.push_back(nums1[i]);
    }

    return ans;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};

    vector<int> ans = nextGreater(arr);
    for(int i: ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}