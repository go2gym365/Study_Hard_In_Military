#include<bits/stdc++.h>

using namespace std;

vector<int> vec;
vector<bool> vis(10, false);

int n, k;
int ans = 0;

void DFS(int cnt, int sum) {
    if(cnt == n && sum >= 500) {
        ans++;
    }

    sum -= k;

    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        if(sum + vec[i] < 500) continue;
        vis[i] = true;
        DFS(cnt + 1, sum + vec[i]);
        vis[i] = false;
    }
}

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }
    
    DFS(1, 500);

    cout << ans;
}