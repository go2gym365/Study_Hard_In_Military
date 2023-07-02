#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v(10, 0);

void DFS(int cnt, int cur) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = cur; i <= n; i++) {
        v[cnt] = i;
        DFS(cnt + 1, i);
        
    }
}

int main() {
    cin >> n >> m;

    DFS(0, 1);
}