#include<bits/stdc++.h>

using namespace std;

int n, m;

int parent[500001];

int find(int x) {
    if(x == parent[x]) return x;
    
    return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y) return true;
    else {
        if(x < y) parent[y] = x;
        else parent[x] = y;
    }
    
    return false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    for(int i = 1; i <= m; i++) {
        int s, e;
        cin >> s >> e;
        
        if(merge(s, e)) {
            cout << i;
            return 0;
        }
    }
    
    cout << 0;
}