#include<bits/stdc++.h>

using namespace std;

priority_queue<int> pq;
priority_queue<int> temp;

int n;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n * n; i++) {
        int a;
        cin >> a;
        
        if(pq.size() < n) {
            pq.push(-a);
        }
        else {
            if(-pq.top() < a) {
                pq.push(-a);
                pq.pop();
            }
        }
    }
    
    cout << -pq.top();
}
