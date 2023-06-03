#include<bits/stdc++.h>

using namespace std;

queue<int> q;
vector<int> ans;

int main() {
    int n, k;
    int cnt = 0;

    cin >> n >> k;
    
    for(int i = 1; i <= n; i++) q.push(i);

    cout << '<';

    while(q.size() != 0) {
        for(int i = 1; i < k; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        if(q.size() != 1) cout << ", ";
        
        q.pop();
    }
    cout << '>';
}