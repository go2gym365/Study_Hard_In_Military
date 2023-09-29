#include<bits/stdc++.h>

using namespace std;

int n, k, w;

int dp[1001];
int Time[1001];
int inDegree[1001];
vector<int> input[1001];

void topologicalSort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) {
            dp[i] = Time[i];
            q.push(i);
        }
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < input[cur].size(); i++) {
            int next = input[cur][i];
            inDegree[next]--;

            dp[next] = max(dp[next], dp[cur] + Time[next]);

            if(!inDegree[next]) {
                q.push(next);    
            }
        }
    }
}

void reset() {
    memset(dp, 0, sizeof(dp));
    memset(Time, 0, sizeof(Time));
    memset(inDegree, 0, sizeof(inDegree));

    for(int i = 0; i < 1001; i++) {
        input[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while(t--) {
        reset();
        cin >> n >> k;

        for(int i = 1; i <= n; i++) {
            cin >> Time[i];
        }

        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            input[a].push_back(b);
            inDegree[b]++;
        }

        cin >> w;
        
        topologicalSort();

        cout << dp[w] << "\n";
    }
}