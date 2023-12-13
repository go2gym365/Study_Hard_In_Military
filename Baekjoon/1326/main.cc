#include <bits/stdc++.h>

using namespace std;

int dist[10001];
int cnt[10001];
bool vis[10001];

int n;
int s, e;

void solve() {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        if(cur == e) return;
        
        for(int i = cur + dist[cur]; i <= n; i += dist[cur]) {
            if(vis[i]) continue;
            vis[i] = true;
            cnt[i] = cnt[cur] + 1;
            q.push(i);
        }
        
        for(int i = cur - dist[cur]; i >= 1; i -= dist[cur]) {
            if(vis[i]) continue;
            vis[i] = true;
            cnt[i] = cnt[cur] + 1;
            q.push(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> dist[i];
    }
    
    cin >> s >> e;

    solve();
    
    if(cnt[e] == 0) cout << -1;
    else cout << cnt[e];
}