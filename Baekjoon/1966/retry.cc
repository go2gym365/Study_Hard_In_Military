#include <bits/stdc++.h>

using namespace std;

int main() {
    int w;
    cin >> w;

    while(w--) {
        int n, m;
        int cnt = 0;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for(int i = 0; i < n; i++) {
            int idx, priority;
            cin >> idx >> priority;
            q.push({idx, priority})
        }
    }
}