#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> input(21, vector<int> (21, 0));
bool check[21];
 
int n;
int ans = 0x3f3f3f3f;
 
void solve(int cnt, int prev) {
    if(cnt == n / 2) {
        int start = 0;
        int link = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(check[i]==true && check[j]==true) start+=input[i][j];
                if(check[i]==false && check[j]==false) link+=input[i][j];
            }
        }
        
        ans = min(ans, abs(start - link));
    }
    for(int i = prev+1; i < n; i++) {
        check[i] = true;
        solve(cnt+1, i);
        check[i] = false;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    solve(0, 0);
    
    cout << ans;
    return 0;
}