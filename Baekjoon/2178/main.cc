#include<bits/stdc++.h>

using namespace std;
int N, M;
vector<vector<bool>> visited(101, vector<bool>(101, false));
vector<vector<int>> maze(101, vector<int>(101, 0));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void BFS(int startx, int starty)
{
    queue<pair<int, int>> q;
    q.push(make_pair(starty, startx));
    visited[starty][startx] = true;

    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++)
        {            
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || ny > N || ny < 1 || nx > M)
                continue;
            if(maze[ny][nx] == 1 && !visited[ny][nx])
            {
                maze[ny][nx] = maze[y][x] + 1;
                q.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    string str;
    for(int i = 1; i <= N; i++)
    {
        cin >> str;
        for(int j = 1; j <= M; j++)
        {
            maze[i][j] = str[j - 1] - '0';
        }
    }

    BFS(1, 1);

    cout << maze[N][M] << endl;
}

