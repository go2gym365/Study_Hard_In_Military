#include<bits/stdc++.h>

using namespace std;

int main() {
    deque<int> dq;
    
    int n;
    cin >> n;
    
    for(int i = n; i > 0; i--) {
        dq.push_back(i);
    }
    
    while(!dq.empty()) {
        cout << dq.back();
        dq.pop_back();
        dq.push_front(dq.back());
        dq.pop_back();
    }
}