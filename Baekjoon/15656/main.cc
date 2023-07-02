#include<bits/stdc++.h>

using namespace std;

int n, m;

vector<int> v(8, 0);
vector<int> k;

void DFS(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        v[cnt] = k[i];
        DFS(cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        k.push_back(a);
    }

    sort(k.begin(), k.end());

    DFS(0);
}