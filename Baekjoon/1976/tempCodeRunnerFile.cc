#include<bits/stdc++.h>

using namespace std;

int n, m;

int vertex[1001];

int find(int x) {
    if(vertex[x] == x)
        return x;
    
    return vertex[x] = find(vertex[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    else vertex[y] = x;
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
    
    for(int i = 1; i <= m; i++) {
        vertex[i] = i;
    }

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            int a;
            cin >> a;
            if(a)
                merge(i, j);
        }
    }

    vector<int> des;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        des.push_back(a);
    }


    for(int i = 1; i < n; i++) {
        check = isUnion(des[i - 1], des[i]);
        if(!check)
            break;
    }

    if(check) cout << "YES";
    else cout << "NO";
}