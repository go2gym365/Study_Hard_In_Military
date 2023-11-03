#include <bits/stdc++.h>

using namespace std;

int n;
int tasktime[10001];
int done[10001];
vector<int> graph[10001];
int dp[10001];

int solve(int cur) {
    int &ret = dp[cur];
    if (ret != -1)
        return ret;

    if (graph[cur].size() == 0) {
        done[cur] = 1;
        return ret = tasktime[cur];
    }

    for (auto& next : graph[cur]) {
        ret = max(ret, solve(next) + tasktime[cur]);
    }

    done[cur] = 1;
    return ret;
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        int cost, cur;
        cin >> cost >> cur;

        tasktime[i] = cost;

        for (int j = 0; j < cur; j++) {
            int d;
            cin >> d;
            graph[d].push_back(i);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (!done[i]) ans = max(ans, solve(i));
    }

    cout << ans;
}
