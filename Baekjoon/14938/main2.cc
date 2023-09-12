#include<bits/stdc++.h>

using namespace std;

int ans = 0;
int n, m, r;
const int INF = 0x3f3f3f3f;

int dist[101][101];
int item[101];

void floyd() {
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
    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j) dist[i][j] = INF;
        }
    }

    for(int i = 1; i <= n; i++) 
        cin >> item[i];
    
    for(int i = 0; i < r; i++) {
        int s, e, c;

        dist[s][e] = c;
        dist[e][s] = c;
    }

    floyd();

    for(int i = 1; i <= n; i++) {
        int cnt = item[i];
        for(int j = 1; j <= n; j++) {
            if(i != j & dist[i][j] <= m)
                cnt += item[j];
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}