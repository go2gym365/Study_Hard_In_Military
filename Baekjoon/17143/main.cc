#include <bits/stdc++.h>

using namespace std;

struct shark {
    int y;
    int x;
    int s;
    int d;
    int size;
    int num;
};

int r, c, m;
int ans = 0;

vector<shark> graph[102][102];

void move(int &cury, int &curx, int &dir) {
    if(dir == 1) {
        if(cury - 1 >= 1) {
            cury--;
        }
        else {
            cury++;
            dir = 2;
        }
    }
    else if(dir == 2) {
        if(cury+1 <= r) {
            cury++;
        }
        else {
            cury--;
            dir = 1;
        }
    }
    else if(dir == 3) {
        if(curx+1 <= c) {
            curx++;
        }
        else {
            curx--;
            dir = 4;
        }
    }
    else if(dir == 4) {
        if(curx-1 >= 1) {
            curx--;
        }
        else {
            curx++;
            dir = 3;
        }
    }
}

void start() {
    int fisherIdx = 0;
    
    while(fisherIdx < c) {
        fisherIdx++;
        
        //물고기 잡기
        for(int i = 1; i <= r; i++) {
            if(!graph[i][fisherIdx].empty()) {
                ans += graph[i][fisherIdx][0].size;
                graph[i][fisherIdx].pop_back();
                break;
            }
        }

        vector<shark> temp[101][101];
        
        //물고기 이동
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if(graph[i][j].empty()) continue;
                
                shark curShark = graph[i][j][0];
                
                int &cury = curShark.y;
                int &curx = curShark.x;
                int moveCnt = curShark.s;
                int &dir = curShark.d;
                
                while(moveCnt--) {
                    move(cury, curx, dir);
                }
                
                if(temp[cury][curx].empty()) {
                    temp[cury][curx].push_back(curShark);
                }
                else {
                    if(temp[cury][curx][0].size < curShark.size) {
                        temp[cury][curx].pop_back();
                        temp[cury][curx].push_back(curShark);
                    }
                }
            }
        }
        
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                graph[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> r >> c >> m;
    
    for(int i = 0; i < m; i++) {
        int y, x, s, d, z;
        cin >> y >> x >> s >> d >> z;
        if(d == 1 || d == 2) s %= ((r-1) * 2);
        if(d == 3 || d == 4) s %= ((c-1) * 2);
        graph[y][x].push_back({y, x, s, d, z, i+1});
    }
    
    start();
    
    cout << ans;
}