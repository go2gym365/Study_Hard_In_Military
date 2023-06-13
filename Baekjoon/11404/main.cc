#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;

vector<vector<int>> v(101, vector<int>(101, INF));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int edge, vertex;

    cin >> vertex;
    cin >> edge;

    for(int i = 0; i < edge; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(v[a][b] > c)
            v[a][b] = c;
    }

    for(int i = 1; i <= vertex; i++) {
        for(int j = 1; j <= vertex; j++) {
            if(i == j) {
                v[i][j] = 0;
                break;
            }
        }
    }

    for(int i = 1; i <= vertex; i++) {
        for(int j = 1; j <= vertex; j++) {
            for(int k = 1; k <= vertex; k++) {
                if (v[j][i] != INF && v[i][k] != INF)
                    v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
            }
        }
    }

    for(int i = 1; i <= vertex; i++) {
        for(int j = 1; j <= vertex; j++) {
            if(v[i][j] == INF) cout << 0 << ' ';
            else cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}