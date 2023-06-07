#include<bits/stdc++.h>

using namespace std;

vector<int> v(102, 0);
vector<bool> vis(102, false);

void BFS(int x, int cnt) {
    queue<pair<int, int>> q;
    q.push({x, cnt});

    while(!q.empty()){
        int location = q.front().first;
        int count = q.front().second;
        q.pop();

        for(int i = 1; i <= 6; i++) {
            int nx = location + i;
            if(nx == 100){
                cout << count + 1;
                return;
            }
            else if(nx < 100) {
                while(v[nx] != 0) {
                    nx = v[nx];
                }
                if(!vis[nx]) {
                    q.push({nx, count + 1});
                    vis[nx] = true;
                }
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        v[a] = b;
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        v[a] = b;
    }

    BFS(1, 0);
}