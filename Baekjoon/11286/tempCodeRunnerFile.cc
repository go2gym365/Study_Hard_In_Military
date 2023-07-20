#include<bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<>> pq;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if(a != 0) {
            pq.push(a);
        }
        else {
            if(pq.empty()) {
                pq.push(0);
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}