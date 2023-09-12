#include<bits/stdc++.h>
#include <queue>
#include <set>

using namespace std;

priority_queue<pair<int, int>> pq;
multiset<int> bag;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, k;
    long long answer = 0;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        pq.push({value, weight});
    }

    for(int i = 0; i < k; i++) {
        int size;
        cin >> size;
        bag.insert(size);
    }
    
    
    while(!bag.empty()) {
        if(pq.empty()) break;
        multiset<int>::iterator iter = bag.lower_bound(pq.top().second);
        if(iter == bag.end()) {
            pq.pop();
            continue;
        }
        else bag.erase(iter);
        answer += pq.top().first;
        pq.pop();
    }

    cout << answer;
}