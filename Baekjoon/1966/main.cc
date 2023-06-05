#include <bits/stdc++.h>

using namespace std;

int main() {
    int w;

    cin >> w;
    while (w--) {
        int n, m;
        int cnt = 0;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;

            q.push({i, k});
            pq.push(k);
        }

        while (!q.empty()) {
            int idx = q.front().first;
            int priority = q.front().second;
            q.pop();

            if (pq.top() == priority) {
                pq.pop();
                cnt++;

                if (idx == m) {
                    cout << cnt << '\n';
                    break;
                }
            }
            else {
                q.push({idx, priority});
            }
        }
    }
}
