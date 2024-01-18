#include<bits/stdc++.h>
 
using namespace std;
 
int f, s, g, u, d;
 
bool vis[1000001];
 
 
int bfs() {
    priority_queue<pair<int, int>> q;
    
    q.push({0, s});
    vis[s] = true;
    
    while(!q.empty()) {
        int cur = q.top().second;
        int cnt = -q.top().first;
        
        q.pop();
        
        if(cur == g) {
            return cnt;
        }
        
        if(cur-d >= 1 && !vis[cur-d]) {
            vis[cur-d] = true;
            q.push({-(cnt+1), cur-d});
        }
        
        if(cur+u <= f && !vis[cur+u]) {
            vis[cur+u] = true;
            q.push({-(cnt+1), cur+u});
        }
    }
    cout << "use the stairs";
    exit(0);
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> f >> s >> g >> u >> d;
    
    cout << bfs();
}