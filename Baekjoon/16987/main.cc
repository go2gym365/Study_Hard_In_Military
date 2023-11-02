#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dura[10];
int weight[10];

int ans = -0x3f3f3f3f;

void solve(int egg) {
    if(egg >= n) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if (dura[i] <= 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }
    
    bool check = false;
    for(int i = 0; i < n; i++) {
        if(egg == i) continue;
        if(dura[egg] <= 0 || dura[i] <= 0) continue;
        dura[egg] -= weight[i];
        dura[i] -= weight[egg];
        check = true;
        solve(egg+1);
        dura[egg] += weight[i];
        dura[i] += weight[egg];
    }
    if(!check) solve(egg + 1);
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> dura[i] >> weight[i];
    }
    
    solve(0);
    
    cout << ans;
}
