#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v(10, 0);
vector<int> k;

void DFS(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0;

    for(int i = 0; i < n; i++) {
        if(k[i] != prev) {
            v[cnt] = k[i];
            DFS(cnt + 1);
            prev = k[i];
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

    DFS(0);
}