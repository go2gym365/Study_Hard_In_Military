#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int>v (8, 0);

void DFS(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        v[cnt] = i;
        DFS(cnt + 1);
    }
}

int main() {
    cin >> n >> m;
    DFS(0);
}