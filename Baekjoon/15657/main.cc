#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v(10, 0);
vector<int> k;

void DFS(int cnt, int cur) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = cur; i < n; i++) {
        v[cnt] = k[i];
        DFS(cnt + 1, i);
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