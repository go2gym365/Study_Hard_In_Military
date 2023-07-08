#include<bits/stdc++.h>

using namespace std;

vector<string> vec(25, "");
vector<vector<bool>> vis(25, vector<bool>(25, false));
vector<int> ans;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n;

void BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    q.push({yy, xx});

    while(!q.empty()) {
        2
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vec[i][j] == '0')
                BFS(i, j);
        }
    }
}