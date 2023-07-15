#include<bits/stdc++.h>

using namespace std;


const int INF = 987654321;
int n, m;
int minValue = INF;
int ans = 0;

vector<vector<int>> vec(101, vector<int>(101, INF));

void floyd() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) {
                    vec[i][j] = 0;
                    continue;
                }
                vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vec[i][j] == INF) {
                vec[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += vec[i][j];
        }
        if(minValue > sum) {
            minValue = sum;
            ans = i + 1;
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int vertex, edge;
        cin >> vertex >> edge;

        vec[vertex - 1][edge - 1] = 1;
        vec[edge - 1][vertex - 1] = 1;
    }

    floyd();

    cout << ans;
}