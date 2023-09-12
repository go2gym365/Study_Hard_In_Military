#include<bits/stdc++.h>
#include <queue>

using namespace std;

int n, k;

vector<int> bag;
vector<pair<int, int>> jems;
priority_queue<int> pq;

long long solve() {
    int idx = 0;
    long long sum = 0;

    for(int i = 0; i < k; i++) {
        // 가방에 들어갈 수 있는 무게를 가진 보석들을 전부 넣기
        while(idx < n && bag[i] >= jems[idx].first) {
            pq.push(jems[idx].second);
            idx++;
        }
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;

        jems.push_back({weight, value});
    }

    for(int i = 0; i < k; i++) {
        int a;
        cin >> a;
        bag.push_back(a);
    }

    sort(jems.begin(), jems.end());
    sort(bag.begin(), bag.end());

    cout << solve();
}