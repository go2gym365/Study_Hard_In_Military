#include<bits/stdc++.h>

using namespace std;


int main() {
    long long int n;
    long long int cnt = 0;
    cin >> n;

    vector<long long int> cost(n, 0);
    vector<long long int> dist(n - 1, 0);

    for(auto &di : dist) {
        cin >> di;
    }

    for (auto &c: cost) {
        cin >> c;
    }
    
    long long int costIdx = 0;
    for(long long int i = 0; i < n - 1; i++) {        
        cnt += cost[costIdx] * dist[i];
        if(cost[costIdx] > cost[i + 1]) {
            costIdx = i + 1;
        }
    }

    cout << cnt;
}