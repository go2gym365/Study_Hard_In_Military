#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int ans = 0x3f3f3f3f;
 
int input[21][21];
bool check[21];
 
int rateCalc() {
    int startRate = 0;
    int linkRate = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(check[i] && check[j]) {
                startRate += input[i][j];
            }
            else if(!check[i] && !check[j]) {
                linkRate += input[i][j];
            }
        }
    }
    
    return abs(startRate-linkRate);
}
 
void solve(int cnt, int idx) {
    if(cnt > n/2) return;
    
    if(cnt > 0) {
        ans = min(ans, rateCalc());
    }
    
    for(int i = idx; i < n; i++) {
        check[i] = true;
        solve(cnt+1, i+1);
        check[i] = false;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    solve(0, 0);
    
    cout << ans;
}