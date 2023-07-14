#include<bits/stdc++.h>

using namespace std;

int n, m;

int vertex[201];
vector<int> path;

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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    bool check = true;
    
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        vertex[i] = i;


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if(a)
                merge(i, j);
        }
    }

    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        path.push_back(a);
    }

    for(int i = 1; i < m; i++) {
        if(find(path[i] != find(path[i + 1]))) {
            check = false;
            break;
        }
    }
    
    if(check) cout << "YES";
    else cout << "NO";
}