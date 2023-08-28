#include<bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n, m;
    int ans;
    long long sum = 0;
    int maxValue = -0x3f3f3f3f;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        pq.push(a);
        sum += a;
        maxValue = max(maxValue, a);
    }

    cin >> m;

    if(m < sum) {
        for(int i = 0; i < n; i++) {
            if(m / (n - i) > pq.top()) {
                m = m - pq.top();
            }
            else {
                ans = m / (n - i);
                break;
            }
            pq.pop();
        }
    }
    else {
        cout << maxValue;
        return 0;
    }

    cout << ans;
}