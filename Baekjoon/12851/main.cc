#include<bits/stdc++.h>

using namespace std;

vector<int> vis(200002, false);

int n , k;

void BFS(int start) {
    queue<pair<int, int>> q;
    vis[start] = true;
    q.push({start, 0});
    
    while(!q.empty()) {
        int nowNode = q.front().first;
        int time = q.front().second;

        q.pop();

        if(nowNode < 0 || nowNode > 100000) continue;
        if(nowNode == k) {
            cout << time;
            break;
        }

        if(!vis[nowNode * 2]) {
            vis[nowNode * 2] = true;
            q.push({nowNode * 2, time + 1});
        }
        if(!vis[nowNode + 1]) {
            vis[nowNode + 1] = true;
            q.push({nowNode + 1, time + 1});
        }
        if(!vis[nowNode - 1]) {
            vis[nowNode - 1] = true;
            q.push({nowNode - 1, time + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    BFS(n);
}