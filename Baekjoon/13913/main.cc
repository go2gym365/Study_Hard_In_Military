#include<bits/stdc++.h>

using namespace std;

int n,k;
vector<bool>vis(1000001, false);
vector<int> temp(1000001, 0);
vector<int> path;

void BFS() {
    queue<pair<int, int>> q;

    vis[n] = true;
    q.push({n, 0});

    while(!q.empty()) {
        int curLoc = q.front().first;
        int time = q.front().second;
        q.pop();
        
        if(curLoc == k) {
            cout << time << "\n";
            
            int idx = curLoc;

            while(idx != n) {
                path.push_back(idx);
                idx = temp[idx];
            }
            path.push_back(n);
            
            break;
        }

        if(!vis[curLoc * 2] && curLoc * 2 <= 100000 ) {
            q.push({curLoc * 2, time + 1});
            vis[curLoc * 2] = true;
            temp[curLoc * 2] = curLoc;
        }
        if(!vis[curLoc - 1] && curLoc - 1 >= 0 ) {
            q.push({curLoc - 1, time + 1});
            vis[curLoc - 1] = true;
            temp[curLoc - 1] = curLoc;
        }
        if(!vis[curLoc + 1] && curLoc + 1 <= 100000 ) {
            q.push({curLoc + 1, time + 1});
            vis[curLoc + 1] = true;
            temp[curLoc + 1] = curLoc;
        }
    }
}

int main() {
    cin >> n >> k;

    BFS();

    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}