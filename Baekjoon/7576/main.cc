#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> visited(1000, vector<bool>(1000, false));;
vector<vector<int>> tomato(1000, vector<int>(1000, 0));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int M, N;

int BFS()
{
    queue<pair<int, int>> q;
    int days = 0;

    for(int i=0; i<M; i++) 
    {
        for(int j=0; j<NA; j++) 
        {
            if(tomato[i][j] == 1) 
            {    
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while(1) {
        queue<pair<int, int>> future;
        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= N || nx < 0 || ny >= M || ny < 0)
                    continue;
                if (tomato[ny][nx] == -1)
                    continue;
                if (visited[ny][nx] == false)
                {
                    visited[ny][nx] = true;
                    future.push(make_pair(ny, nx));
                }
            }
        }

        if(future.empty()) {
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if(tomato[i][j] != -1 && visited[i][j] == false) return -1;
                }
            }
            return days;
        }
        q = future;
        days++;
    }
    return 1203274;
}

int main() 
{
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> tomato[i][j];
        }
    }

    cout << BFS();
}