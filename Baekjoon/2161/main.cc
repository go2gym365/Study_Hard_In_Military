#include<bits/stdc++.h>

using namespace std;

int main() {
    deque<int> dq;
    queue<int> q;
    
    int n;
    cin >> n;
    
    for(int i = n; i > 0; i--) {
        dq.push_back(i);
    }
    
    while(!dq.empty()) {
        q.push(dq.back());
        dq.pop_back();
        
        if(!dq.empty()) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        else {
            break;
        }
    }
    
    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
}