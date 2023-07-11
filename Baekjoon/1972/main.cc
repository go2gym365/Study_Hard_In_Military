#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    priority_queue<int, vector<int>, greater<>> pq;

    int n;
    int cnt = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == 0) {
            if(pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(a);
    }      
}