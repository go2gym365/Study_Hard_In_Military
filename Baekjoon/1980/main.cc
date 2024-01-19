#include<bits/stdc++.h>

using namespace std;

int n, m, t;

int tower(int fireCnt) {
    
    return (t - fireCnt*m) / n;
}

int fire(int towerCnt) {
    return (t - towerCnt*n)/m;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    priority_queue<pair<int, int>> pq;
    
    cin >> n >> m >> t;
    
    //i의 기준 > 불고기버거의 갯수
    for(int i = 0; i <= (t/m); i++) {
        int towerCnt = tower(i);
        int fireCnt = fire(towerCnt);
        
        int cokeTime = t - towerCnt*n - fireCnt*m;
        
        pq.push({-cokeTime, towerCnt+fireCnt});
    }

    cout << pq.top().second << ' ' << -pq.top().first << '\n';
}