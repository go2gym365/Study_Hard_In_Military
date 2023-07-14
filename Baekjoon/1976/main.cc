#include<bits/stdc++.h>

using namespace std;

int n, m;

int vertex[1001];

int find(int x) {
    if(vertex[x] == x)
        return vertex[x];
    
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

    for(int i = 1; i <= m; i++) {
        vertex[i] = i;
    }

    for(int i = 1; i <= m; i++) {
        int a;
        cin >> a;

        if(a)
            merge(i, a);
    }

    vector<int> des;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        des.push_back(a);
    }

    bool check = true;

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            check = isUnion(des[i], des[j]);
            if(!check) 
                break;
        }        
    }

    if(check) cout << "YES";
    else cout << "NO";
}