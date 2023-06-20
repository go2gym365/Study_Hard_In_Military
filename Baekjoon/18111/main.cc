#include<bits/stdc++.h>

using namespace std;

int n, m, b;

vector<int> v(501, vector<int>(501, 0));
vector<pair<int, int>> ans;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void dig() {
    int sec = 0;
    int frist = 987654321;

    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            first = min(first, v[i][j]);
        }
    }

    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(v[i][j] != first) {
                sec += (v[i][j] - first) * 2;
                v[i][j] = first;
            }
        }
    }
    ans.push_back({sec, v[0][0]});
}

int struc() {
    int sec = 0;
    int mx = -987654321;

    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            mx = max(mx, v[i][j]);
        }
    }

    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            if(v[i][j] != mx && b > 0) {
                sec += mx - v[i][j];
                b -= mx - v[i][j];
                v[j][i] = mx;
            }
            else break;
        }
    }

    while(b > n * m) {
        v[0][0]++;
        sec += n * m;
        b -= n * m;
    }

    ans.push_back({sec, v[0][0]});
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cin.tie(0);

    cin >> n >> m >> b;

    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    
    cout << ans.front().first << " " << ans.front().second;
}