#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, totalCost = 0;
    
    int st = 0, currGas = 0;
    for(int i=0; i<gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        currGas += (gas[i]-cost[i]);
        
        if(currGas <0) {
            st = i+1;
            currGas = 0;
        }
    }
    
    return totalGas < totalCost? -1: st;
}

int main() {
    vector<int> gas = {1, 2, 4, 5, 9};
    vector<int> cost = {3, 4, 1, 10, 1};

    cout<<canCompleteCircuit(gas, cost)<<endl;
    return 0;
}