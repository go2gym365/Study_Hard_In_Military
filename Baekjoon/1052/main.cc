#include<bits/stdc++.h>

using namespace std;

bitset<32> bs;
int ans;
int n, k;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    while(true) {
        int temp = n;
        int firstOnIdx = -1;
        
        int cnt = 0;
        int idx = 0;
        while(temp) {
            if(temp & 1) {
                if(firstOnIdx == -1) firstOnIdx = idx;
                cnt++;
            }
            idx++;
            temp >>= 1;
        }
        
        if(cnt <= k) break;
        else {
            n += (1<<firstOnIdx);
            ans += (1<<firstOnIdx);
        }
    }
    
    cout << ans;
}
