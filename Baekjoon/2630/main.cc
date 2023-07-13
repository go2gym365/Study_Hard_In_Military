#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> vec(128, vector<int>(128));
int white = 0;
int blue = 0;

void solve(int x, int y, int width) {
    // 다 찼는지 안 찼는지 검사
    // 만약에 1로 다 찼다 blue ++;
    // 0으로 다 찼다? white++;
    bool check = true;

    for(int i = y; i < y + width; i++) {
        for(int j = x; j < x + width; j++) {
            if(vec[y][x] != vec[i][j]) {
                check = false;
                break;
            }
        }
        if(!check) break;
    }

    // 찼다면 ? return
    if(check) {
        if(vec[y][x] == 1) {
            blue++;
            return;
        }
        else if(vec[y][x] == 0) {
            white++;
            return;
        }
    }
    // 안찼다면 ?
    // 4개로 쪼개기
    int divided = width / 2;
    solve(x, y, divided);
    solve(x + divided, y, divided);
    solve(x , y + divided, divided);
    solve(x + divided, y + divided, divided);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> vec[i][j];
        }
    }

    solve(0, 0, N);

    cout << white << "\n" << blue;
}