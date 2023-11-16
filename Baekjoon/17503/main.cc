#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long n, m, k;

vector<pair<long long, long long>> beer;
priority_queue<long long> pq;

bool compare(pair<long long, long long> & a, pair<long long, long long> &b) {
    if(a.first < b.first) return true;
    else if(a.first == b.first) return a.second > b.second;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++) {
        long long prefer, alc;
        cin >> prefer >> alc;
        beer.push_back({alc, prefer});
    }
    sort(beer.begin(), beer.end(), compare);
    
    long long sum = 0;
    
    for(int i = 0; i < k; i++) {
        //도수가 낮은거부터 빼려고
        pq.push(-beer[i].second);
        sum += beer[i].second;
        
        if(pq.size() > n) {
            sum += pq.top();
            pq.pop();
        }
        
        //큰 값으로 정렬해놨기 때문에 i가 커질수록 큰 값만 반환함
        if(pq.size() == n && sum >= m) {
            cout << beer[i].first;
            return 0;
        }
    }

    cout << -1;
}
