#include <bits/stdc++.h>

using namespace std;

int node[100001];
bool group[100001];
bool vis[100001];

int n;
int ans;

void solve(int firstChoice) {
    vis[firstChoice] = true;
    int next = node[firstChoice];
    
    if(!vis[next]){ 
        solve(next);
    }
    else if(!group[next]) {
        for(int i = next; i != firstChoice; i = node[i])  {
            ans++;
        }
        ans++;
    }
    
    group[firstChoice] = true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        memset(vis, false, sizeof(vis));
        memset(group, false, sizeof(group));
        ans = 0;
        
        cin >> n;
        
        for(int i = 1; i <= n; i++) {
            cin >> node[i];
        }
        
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            solve(i);
        }
        
        cout << n - ans << "\n";
    }
}