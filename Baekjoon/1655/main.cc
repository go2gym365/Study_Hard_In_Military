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

        //최대 힙의 크기는 최소 힙의 크기와 같거나 하나 더 큼
        // 최대 힙의 최대 원소는 최소 힙의 최소 원소보다 작거나 같다
        // > 알고리즘에 맞지 않으면 최대힙 최소힙 가장 최상단 값을 Swap
        
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

