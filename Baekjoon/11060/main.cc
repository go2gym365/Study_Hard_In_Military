#include<bits/stdc++.h>
 
using namespace std;
 
int n;
 
int arr[1001];
bool vis[1001];
 
int bfs() {
    queue<pair<int, int>> q;
    int ans = 0x3f3f3f3f;
    
    q.push({0, 0});
    vis[0] = true;
    
    while(!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        
        q.pop();
        
        if(cur == n-1) {
            return cnt;
        }
        
        for(int i = 1; i <= arr[cur]; i++) {
            int next = cur + i;
            
            if(vis[next]) continue;
            
            if(next < n) {
                q.push({next, cnt+1});
                vis[next] = true;
            }
        }
    }
    
    return -1;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << bfs();
}