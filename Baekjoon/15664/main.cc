#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v(10, 0);
vector<bool> vis(10, false);
vector<int> k;

void DFS(int cnt, int cur) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    int before = 0;

    for(int i = cur; i < n; i++) {
        if(!vis[i]) {
            if(k[i] == before) continue;
            v[cnt] = k[i];
            before = k[i];
            vis[i] = true;
            DFS(cnt + 1, i);
            vis[i] = false;
        }
    }
}

int main() { 
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        k.push_back(a);
    }

    sort(k.begin(), k.end());

    DFS(0, 0);
}