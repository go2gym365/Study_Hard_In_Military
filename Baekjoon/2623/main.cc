#include<bits/stdc++.h>

using namespace std;

int n, m;

int inDegree[1001];
vector<int> input[1001];
vector<int> ans;

void topologicalSort() {
    queue<int> q;

    for(int i = 1; i <= n; i++) {
        if(!inDegree[i])
            q.push(i);
    }

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur);

        for(int i = 0; i < input[cur].size(); i++) {
            int next = input[cur][i];
            inDegree[next]--;

            if(!inDegree[next]) {
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int cur;
        int prev;
        cin >> cur;
        cin >> prev;
        for(int j = 0; j < cur - 1; j++) {
            int a;
            cin >> a;
            input[prev].push_back(a);
            inDegree[a]++;
            prev = a;
        }
    }

    topologicalSort();

    if(ans.size() != n) {
        cout << 0;
    }
    else {
        for(int i = 0; i < n; i++) {
            cout << ans[i] << "\n";
        }
    }
}