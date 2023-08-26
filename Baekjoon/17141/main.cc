#include<bits/stdc++.h>

using namespace std;

int n, m;
int answer = -9572691;

vector<vector<int>> vec(51, vector<int> (51, 0));
vector<vector<bool>> vis(51, vector<bool> (51, 0));
vector<pair<int, int>> virus;

void combination(int cnt) {
    if(cnt == m) {
        int res = BFS();
        answer = max(answer, res);
        return;
    }

    for(int i = cnt; i < m; i++) {
        q.push({virus[cnt].first, virus[cnt].second});
    }
}

int main() {
    cin >> n, m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; i < n; j++) {
            cin >> vec[i][j];

            if(vec[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    combination(0);
}