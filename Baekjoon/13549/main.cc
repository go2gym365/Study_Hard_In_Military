#include<bits/stdc++.h>

using namespace std;

int n, k;
int ans = 0;

vector<bool> vis(200001, false);

void BFS() {
    queue<pair<int, int>> q;
    q.push({n, 0});
    vis[n] = true;

    while(!q.empty()) {
        int curLoc = q.front().first;
        int time = q.front().second;
        vis[curLoc] = true;
        
        if(curLoc == k) {
            cout << time;
            break;
        }

        q.pop();

        if(curLoc * 2 <= 100000 && !vis[curLoc * 2]) {
            q.push({curLoc * 2, time});
        }
        if(curLoc - 1 >= 0 && !vis[curLoc - 1]) {
            q.push({curLoc - 1, time + 1});
        }
        if(curLoc + 1 <= 100000 && !vis[curLoc + 1]) {
            q.push({curLoc + 1, time + 1});
        }
    }
}

int main() {
    cin >> n >> k;

    BFS();
}