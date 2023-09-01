#include<bits/stdc++.h>

using namespace std;

int n, m, r;
const int INF = 0x3f3f3f3f;

//vector<vector<int>> vec(101, vector<int> (101, 0));
vector<vector<int>> dist(101, vector<int> (101, INF));
int item[101];

void floyd() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) dist[i][j] = 0;
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    for(int i = 0; i < r; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        dist[s][e] = c;
        dist[e][s] = c;
    }

    floyd();

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 0; j <= n; j++) {
            if(dist[i][j] <= m) {
                sum += item[j];
            }
        }
        ans = max(ans, sum);
    }

    cout << ans;
}