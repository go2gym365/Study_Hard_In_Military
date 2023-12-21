#include <bits/stdc++.h>

using namespace std;

bool vis[101][101];
bool apple[101][101];

deque<pair<int, int>> snake;
queue<pair<int, char>> cmd;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, k, l;

int start() {
    int cnt = 0;
    int dir = 2;
    
    vis[0][0] = true;
    snake.push_front({0, 0});
    
    while(true) {
        //뱀 옮기기
        int nx = snake.front().second + dx[dir];
        int ny = snake.front().first + dy[dir];
        snake.push_front({ny, nx});
        cnt++;
        
        //게임에서 지게되는 조건
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) {
            break;
        }
        if(vis[ny][nx]) break;
        
        //이게 앞에 가면 뱀 머리랑 겹쳐서 바로 끝남
        vis[ny][nx] = true;
        
        //사과에 대한 조건
        if(!apple[ny][nx]) {
            int tailX = snake.back().second;
            int tailY = snake.back().first;
            vis[tailY][tailX] = false;
            snake.pop_back();
        }
        else {
            //사과 먹었으면 없애주기
            apple[ny][nx] = false;
        }
        
        if(cmd.front().first == cnt) {
            if(cmd.front().second == 'D') {
                dir = (dir+1) % 4;
            }
            else {
                dir = (dir+3) % 4;
            }
            cmd.pop();
        }
        
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    for(int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        
        apple[y-1][x-1] = true;
    }
    
    cin >> l;
    
    for(int i = 0; i < l; i++) {
        int t;
        char command;
        
        cin >> t >> command;
        
        cmd.push({t, command});
    }
    
    cout << start();
}