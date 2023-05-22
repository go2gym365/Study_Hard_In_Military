#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
int N, hunt = 0, sec = 0, size = 2;
vector<vector<int>> space(20, vector<int>(20, 0));
vector<vector<int>> visited(20, vector<int>(20, 0));
int minDes = 987654321;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int minx = 0, miny = 0;

void BFS()
{
    queue<pair<int, int>> q;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(space[i][j] == 9)
            {
                q.push({i, j});
                miny = i;
                minx = j;
                visited[i][j] == 1;
            }    
        }
    }

    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= N || nx < 0 || ny >= N || ny < 0)
                continue;
            if(visited[ny][nx] || space[ny][nx] > size)
                continue;
            if(space[ny][nx] < size && visited[ny][nx] == 0)
            {
                if(space[ny][nx] > 0)
                    space[ny][nx] *= -1;
                if(minDes > visited[miny][minx] + 1)
                    minDes = visited[miny][minx] + 1;
                hunt++;
                sec++;
                q.push({ny, nx});
                visited[miny][minx] += 1;
            }
            else if(space[ny][nx] == 0 || space[ny][nx] >= size)
            {
                q.push({ny, nx});
                visited[miny][minx] += 1;
            }
        }

        if(hunt == size)
            size++;
    }
}

bool compare(vi& a, vi& b) {
    // a[0] -> distance
    // a[1] -> y
    // a[2] -> x
    if(a[0] != b[0]) return a[0] < b[0];
    if(a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> space[i][j];
        }
    }

    // 현재 물고기 위치 탐색
    // curX, curY

    BFS();

    while(1) 
    {
        // 기저조건 : 모든 space를 전부 탐색 했을 떄 먹을게 없을 때
        bool check = true;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                
                if(space[i][j] > 0)
                {
                    check = true;
                    break;
                }
                else if(space[i][j] == 0)
                    check = false;
            }
        }
        if(check == false)
        // 큐에다가 curX, curY bfs
        // 먹을 수 있는 물고기 리스트 : eatable
        
        // (dist, y, x)

        sort(eatable.begin(), eatable.end(), compare);
        // eatable[0]

        // 먹은 물고기를 0으로
        // 현재 위치를 먹은 물고기 위치로

        // 1초 증가
        // 개수 올리고
    }

    cout << sec;
}