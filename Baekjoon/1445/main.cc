#include <bits/stdc++.h>

using namespace std;

int n, m;

int sx, sy;
int fx, fy;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

char graph[51][51];
int dist[51][51];

void dijkstra() {
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
    
    int onTrashCnt = 0;
    int betweenTrashCnt = 0;
    
    pq.push({{0, 0}, {sy, sx}});
    memset(dist, -1, sizeof(dist));
    
    dist[sy][sx] = 0;
    
    while(!pq.empty()) {
        int findCheck = false;
        
        int onTrash = pq.top().first.first;
        int betweenTrash = pq.top().first.second;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        
        pq.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny == fy && nx == fx) {
                onTrashCnt = onTrash;
                betweenTrashCnt = betweenTrash;
                findCheck = true;
                break;
            }
            
            if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if(dist[ny][nx] != -1) continue;
            
            if(graph[ny][nx] == 'g') {
                pq.push({{onTrash+1, betweenTrash}, {ny, nx}});
            }
            else if(graph[ny][nx] == '.') {
                bool trashCheck = false;
                for(int j = 0; j < 4; j++) {
                    if(graph[ny+dy[j]][nx + dx[j]] == 'g') {
                        trashCheck = true;
                        break;
                    }
                }
                if(trashCheck) pq.push({{onTrash, betweenTrash+1}, {ny, nx}});
                else pq.push({{onTrash, betweenTrash}, {ny, nx}});
            }
            
            dist[ny][nx] = dist[y][x] + 1;
        }
        if(findCheck) break;
    }
    
    cout << onTrashCnt << " " << betweenTrashCnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> graph[i][j];
            
            if (graph[i][j] == 'S') {
				sy = i;
				sx = j;
			}
			else if (graph[i][j] == 'F') {
				fy = i;
				fx = j;
			}
        }
    }
    
    dijkstra();
}