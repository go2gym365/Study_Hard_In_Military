#include<bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, less<>> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;

int main() {
    int n;
    cin >> n;
     
     for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if(maxHeap.empty()) {
            maxHeap.push(a);
        }
        else if(maxHeap.size() == minHeap.size()) {
            maxHeap.push(a);
        }
     }
}