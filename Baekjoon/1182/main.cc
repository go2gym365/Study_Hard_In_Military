#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> k;

int cnt = 0;

void DFS(int cur, int sum) {
    if(cur == n) return;
    
    if(sum + k[cur] == m) cnt++;

    DFS(cur + 1, sum);
    DFS(cur + 1, sum + k[cur]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        k.push_back(a);
    }

    DFS(0, 0);

    cout << cnt;
}