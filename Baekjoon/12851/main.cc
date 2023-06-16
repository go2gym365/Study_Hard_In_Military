#include<bits/stdc++.h>

using namespace std;

vector<bool> vis(200002, false);

int n, k, t = 0;
int cnt = 0;

void BFS() {
    queue<pair<int, int>> q;
    vis[n] = true;
    q.push({n, 0});
    
    while(!q.empty()) {
        int curLoc = q.front().first;
        int time = q.front().second;
        
        q.pop();
        vis[curLoc] = true;

        if(cnt && curLoc == k && t == time) cnt++;

        if(!cnt && curLoc == k) {
            t = time;
            cnt++;
        }
        
        if(curLoc * 2 <= 100000 && !vis[curLoc * 2]) {
            q.push({curLoc * 2, time + 1});
        }
        if(curLoc + 1 <= 100000 && !vis[curLoc + 1]) {
            q.push({curLoc + 1, time + 1});
        }
        if(curLoc- 1 >= 0 && !vis[curLoc - 1]) {
            q.push({curLoc - 1, time + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    BFS();

    cout << t << "\n" << cnt;
}