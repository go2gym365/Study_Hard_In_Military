#include<bits/stdc++.h> 
using namespace std;
const int INF = 987654321;

vector<string> maze;
vector<vector<int>> dist(101, vector<int>(101, INF));

int M, N, answer;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq; //cost, y, x
    pq.push({0, {0, 0}});
    
    while(!pq.empty()) {
        int x, y, cnt;
        x = pq.top().second.second;
        y = pq.top().second.first;
        cnt = -pq.top().first;
        pq.pop();

        if(dist[y][x] < cnt) continue;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncnt = cnt;

            if(nx >= M || nx < 0 || ny >= N || ny < 0) continue;
            if(maze[ny][nx] == '1') ncnt++;

            if(dist[ny][nx] > ncnt) {
                dist[ny][nx] = ncnt;
                pq.push({-ncnt, {ny, nx}});
            }
        }
    }
}

int main() {
    cin >> M >> N;

    for(int i = 0 ; i < N; i++) {
        string str;
        cin >> str;
        maze.push_back(str);
    }
    
    dijkstra();
    
    cout << dist[N-1][M-1];
}