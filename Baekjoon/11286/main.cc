#include<bits/stdc++.h>

using namespace std;

struct cmp {
    bool operator() (int  a, int b) {
        if(abs(a) == abs(b)) {
            return a > b;
        }
        else
            return abs(a) > abs(b);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    priority_queue<int, vector<int>, cmp> pq;
    
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
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
}