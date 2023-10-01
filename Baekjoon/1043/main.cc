#include<bits/stdc++.h>

using namespace std;

int n, m, k;

int node[51];
vector<vector<int>> party(51);
vector<int> know;

int find(int x) {
    if(node[x] == x) return x;

    return node[x] = find(node[x]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);

    if(x == y) return;
    
    if(x < y) node[y] = x;
    else node[x] = y;
}

bool isUnion(int a, int b) {
    int x = find(a);
    int y = find(b);

    if(x == y) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < k; i++) {
        int knowP;
        cin >> knowP;
        know.push_back(knowP);
    }

    for(int i = 1; i <= n; i++) node[i] = i;

    for(int i = 0; i < m; i++) {
        int cur;
        cin >> cur;
        int prev;
        cin >> prev;
        party[i].push_back(prev);
        for(int j = 1; j < cur; j++) {
            int after;
            cin >> after;

            merge(prev, after);
            prev = after;
            party[i].push_back(after);
        }
    }
    for(int i = 0; i < party.size(); i++) {
        bool check = false;
        for(int j = 0; j < party[i].size(); j++) {
            if(check) break;
            for(int k = 0; k < know.size(); k++) {
                if(isUnion(party[i][j], know[k])) {
                    check = true;
                    break;
                }
            }
        }
        if(check) m--;
    }
    cout << m;
}