#include<bits/stdc++.h>
using namespace std;

int N, M, R;
int cnt = 0;

vector<int> result[100001];
vector<int> v[100001];
vector<bool> vis(100001, false);

void BFS(int start) {
    queue<int> q;
    vis[start] = true;
    q.push(start);
    cnt++;
    result[start] = cnt;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int e : v[node]) {
            if(!vis[e]) {
                cnt++;
                q.push(e);
                vis[e] = true;
                result[e] = cnt;
            }
        }
    }
}

int main() {
    cin >> N >> M >> R;
    while(M--) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
        sort(v[i].begin(), v[i].end());

    BFS(R);

    for (int i = 1; i <= n; i++) {
		cout << result[i] << "\n";
	}
}