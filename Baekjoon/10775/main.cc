#include<bits/stdc++.h>

using namespace std;

int g, p;
int ans = 0;

int parent[100001];

int find(int x) {
    if(parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(x < y) parent[y] = x;
    else parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> g >> p;

    for(int i = 1; i <= g; i++) parent[i] = i;

    for(int i = 0; i < p; i++) {
        int a;
        cin >> a;

        if(find(a) == 0) break;
        else {
            ans++;
            merge(find(a), find(a) - 1);
        }
    }

    cout << ans;
}