#include<bits/stdc++.h>

using namespace std;

priority_queue<long long, vector<long long>, greater<>> pq;

int main() {
    long long n, cnt;
    cin >> n >> cnt;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    for(int i = 0; i < cnt; i++) {
        long long fir = pq.top();
        pq.pop();
        long long sec = pq.top();
        pq.pop();

        long long sum = fir + sec;

        pq.push(sum);
        pq.push(sum);
    }

    long long ans = 0;
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}