#include<bits/stdc++.h>

using namespace std;

int n, m;

int vertex[1001];
int node[1001];

int find(int x) {
    if(vertex[x] == x)
        return x;
    
    return vertex[x] = find(vertex[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x < y) vertex[y] = x;
    else vertex[x] = y;
}

bool isUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) 
        return true;
    else 
        return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bool check = true;
    
    for(int i = 1; i <= n; i++) {
        vertex[i] = i;
    }

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if(a)
                merge(i, j);
        }
    }

    cin >> node[0];

    for(int i = 1; i < m; i++) {
        cin >> node[i];
        if(!isUnion(node[i - 1], node[i])){
            check = false;
            break;
        }
    }

    if(check) cout << "YES";
    else cout << "NO";
}