#include<bits/stdc++.h>

using namespace std;

int n, m, k;

vector<int> vec[30001];
bool vis[30001];
int value[30001];
vector<pair<int, int>> ans;

int dp[30001][3001];

int solve(int idx, int cnt) {
    if(idx >= ans.size()) return 0;
    int &ret = dp[idx][cnt];
    if(ret != -1) return ret;
    ret = 0;
    
    if(cnt + ans[idx].first < k) {
        ret = max(ret, solve(idx + 1, cnt + ans[idx].first) + ans[idx].second);
    }
    ret = max(ret, solve(idx + 1, cnt)); 
    
    return ret;
}

void BFS(int start) {
    priority_queue<int> pq;

    int save = value[start];
    int cnt = 1;

    pq.push(start);
    vis[start] = true;

    while(!pq.empty()) {
        int here = pq.top();
        pq.pop();
        
        for(int i = 0; i < vec[here].size(); i++) {
            int next = vec[here][i];
            if(vis[next]) continue;
            pq.push(next);
            vis[next] = true;
            cnt++;
            save += value[next];
        }
    }
    ans.push_back({cnt, save});
}

int main() {
    memset(dp, -1, sizeof(dp));
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        value[i] = a;
    }

    for(int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;

        vec[start].push_back(end);
        vec[end].push_back(start);
    }

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        BFS(i);
    }

    cout << solve(0, 0);
}