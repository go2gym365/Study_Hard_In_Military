#include<bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, less<>> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
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
        else {
            minHeap.push(a);
        }

        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.push(minHeap.top());
            minHeap.pop();
            maxHeap.pop();
        }

        cout << maxHeap.top() << "\n";;
     }
}

