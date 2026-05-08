#include<iostream>
#include<vector> 
#include <stack>
using namespace std;

int largestRectangle(vector<int>& height) {
    int ans = 0;

    for(int i=0; i<height.size(); i++) {
        for(int j=i+1; j<height.size(); j++) {
            int wd = j-i;
            int ht = min(height[i], height[j]);
            int area = wd*ht;

            ans = max(area, ans);
        }
    }

    return ans;
}

int largestRectangleArea(vector<int>& height) {
    stack<int> s;
    vector<int> right(height.size(), 0);
    vector<int> left(height.size(), 0);

    for(int i=height.size()-1; i>=0; i--) {
        while (s.size() > 0 && height[s.top()]>=height[i]) {
            s.pop();
        }

        right[i] = s.empty()? height.size(): s.top();
        s.push(i);
    }

    while (!s.empty()) {
        s.pop();
    }
    

    for(int i=0; i<height.size(); i++) {
        while (s.size() > 0 && height[s.top()]>=height[i]) {
            s.pop();
        }

        left[i] = s.empty()? -1: s.top();
        s.push(i);
    }

    int ans = 0;
    for(int i=0; i<height.size(); i++) {
        int wd = right[i]-left[i]-1;
        int currArea = height[i]*wd;
        ans = max(ans, currArea);
    }

    return ans;
}

int main() {
    vector<int> height = {2, 1, 5, 6, 2, 3};

    cout<<"Largest Rectangle: "<<largestRectangleArea(height)<<endl;
    return 0;
}