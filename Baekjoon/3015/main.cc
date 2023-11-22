#include <bits/stdc++.h>

using namespace std;

int n;

stack<pair<int, int>> sta;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    long long pairCnt = 0;
    
    for(int i = 0; i < n; i++) {
        int height;
        cin >> height;
        
        int sameHeightCnt = 1;
        
        while(!sta.empty() && sta.top().first < height) {
            pairCnt += sta.top().second;
            sta.pop();
        }
        
        if(!sta.empty()) {
            if(sta.top().first == height) {
                pairCnt += sta.top().second;
                sameHeightCnt += sta.top().second;
                
                if(sta.size() > 1) pairCnt++;
                
                sta.pop();
            }
            else {
                pairCnt++;
            }
        }
        sta.push({height, sameHeightCnt});
    }
    
    cout << pairCnt;
}
