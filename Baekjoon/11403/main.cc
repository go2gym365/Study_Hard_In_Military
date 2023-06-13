#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v(101, vector<int>(101, 0));

const int INF = 987654321;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> v[i][j];
            if(v[i][j] == 0) v[i][j] = INF;
        }
    }

    //거쳐가는 노드
    for(int i = 0; i < n; i++) {
        //출발 노드
        for(int j = 0; j < n; j++) {
            //도착노드
            for(int k = 0; k < n; k++) {
                v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(v[i][j] == INF) 
                cout << 0 << ' ';
            else 
                cout << 1 << ' ';
        }
        cout << "\n";
    }
}