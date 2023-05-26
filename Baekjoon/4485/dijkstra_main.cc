#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> m(126, vector<int> (126, 0));

int dijkstra() {
    
}

int main() {
    int idx = 0;
    while(1) {
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> m[i][j];
            }
        }
        ++idx;
        cout << "Problem " << idx << ": " << dijkstra(0, 0) << '\n';
    }
}