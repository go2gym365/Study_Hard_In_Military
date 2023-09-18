#include<bits/stdc++.h>

using namespace std;

//좌, 상, 우, 하
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int n, m;
int loc[8][8];
vector<pair<int, int>> cctv;
int answer = 64;

void check(int y, int x, int dir) {
    dir %= 4;

    while(true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        //while문이기 때문에 다음 같은열 다음 좌표를 구해주기 위해 다음 좌표값을 미리 넣어줌
        y = ny; x = nx;
        if (nx < 0 || ny < 0 || ny >= n || nx >= m)return;
        if (loc[ny][nx] == 6) return; //벽
        if (loc[ny][nx] != 0) continue; //cctv
        loc[ny][nx] = '#';
    }
}

void solve(int cnt) {
    if(cnt == cctv.size()) {
        int tempAnswer = 0; //현재 선택한 방향의 사각지대 최솟값 계산하여 저장
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(loc[i][j] == 0) tempAnswer++;
            }
        }
        answer = min(answer, tempAnswer);
        return;
    }

    int y = cctv[cnt].first;
    int x = cctv[cnt].second;
    //입력받은 배열을 임시 배열에 저장해서 계산 후 다시 돌려놔야함
    int backUpArr[8][8];

    //동, 서, 남, 북 4방향 회전
    for(int dir = 0; dir < 4; dir++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                backUpArr[i][j] = loc[i][j];
            }
        }

        if(loc[y][x] == 1) {
            check(y, x, dir + 2); //dir == 0일때 오른쪽
        }
        else if(loc[y][x] == 2) {
            check(y, x, dir); //dir == 0일때 왼쪽
            check(y, x, dir + 2); //dir == 0일때 오른쪽
        }
        else if(loc[y][x] == 3) {
            check(y, x, dir + 1); //dir == 0일때 위쪽
            check(y, x, dir + 2); //dir == 0일때 오른쪽
        }
        else if(loc[y][x] == 4) {
            check(y, x, dir); //dir == 0일때 왼쪽
            check(y, x, dir + 1); //dir == 0일때 위쪽
            check(y, x, dir + 2); //dir == 0일때 오른쪽
        }
        else if(loc[y][x] == 5) {
            check(y, x, dir); //dir == 0일때 왼쪽
            check(y, x, dir + 1); //dir == 0일때 위쪽
            check(y, x, dir + 2); //dir == 0일때 오른쪽
            check(y, x, dir + 3); //dir == 0일때 아래쪽
        }
        solve(cnt + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                loc[i][j] = backUpArr[i][j];
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> loc[i][j];
            if(loc[i][j] >= 1 && loc[i][j] <= 5)
                cctv.push_back({i, j});
        }
    }
    solve(0);
    cout << answer;
}