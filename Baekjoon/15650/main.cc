#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v(8, 0);
vector<bool> vis(8, false);

void DFS(int num, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = num; i <= n; i++) {
        if(!vis[i]) {
            vis[i] = true;
            v[cnt] = i;
            DFS(i + 1, cnt + 1);
            vis[i] = false;
        }
    }    
}

int main() {
    cin >> n >> m;
    DFS(1, 0);
}