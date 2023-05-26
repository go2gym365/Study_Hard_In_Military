#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> m(126, vector<int> (126, 0));

int BFS(int yy, int xx) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(126, vector<int>(126, INF));
    dist[yy][xx] = m[yy][xx];
    q.push({yy, xx});

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= N || ny < 0 || nx < 0 || ny >= N)  continue;
            int next_cost = dist[y][x] + m[ny][nx];
            if(dist[ny][nx] > next_cost) {
                dist[ny][nx] = next_cost;
                q.push({ny, nx});
            }
        }
    }

    return dist[N-1][N-1];
}

struct compare {
    bool operator () (vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};

int dijkstra(int y, int x) {
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    vector<vector<int>> dist(126, vector<int>(126, INF));
    dist[y][x] = m[y][x];
    pq.push({m[y][x], y, x});

    while(!pq.empty()) {
        int x = pq.top()[2];
        int y = pq.top()[1];
        int cost = pq.top()[0];
        pq.pop();

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= N || ny < 0 || nx < 0 || ny >= N)  continue;
            int next_cost = cost + m[ny][nx];
            if(dist[ny][nx] > next_cost) {
                dist[ny][nx] = next_cost;
                pq.push({next_cost, ny, nx});
            }
        }
    }

    return dist[N-1][N-1];
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