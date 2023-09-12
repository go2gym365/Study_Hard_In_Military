#include<bits/stdc++.h>
#include <ios>

using namespace std;

vector<string> vec(1001, "");

int cnt = 0;

int n, m, k;

void check(int y, int x) {
    bool chk = true;
    for(int i = x; i < x + k; i++) {
        if(i >= m || vec[y][i] == '1') {
            chk = false;
            break;
        }
    }
    if(chk) cnt++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vec[i][j] == '1') continue;
            check(i, j);
        }
    }

    cout << cnt;
}