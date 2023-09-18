#include <bits/stdc++.h>

using namespace std;

int arr[8][8];
bool vis[8][8];

int n, m;
int ans = 0;

int solve(int y, int x, int type, int prev) {
    if (y < 0 || y > n || x < 0 || x > n) return 0;
    if (arr[y][x] == 6) return 0;


    int ret = -987654321;
    int temp = -1;
    //prev > 0 처음 시작
    if (prev == 0) {
        // cctv타입이 1
        if (type == 1) {
            // prev > 어느쪽으로 갔는지
            if(prev == 1) { //동
                temp = max(temp, solve(y, x+1, 1, 1) + 1);
                ret = max(ret, temp); temp = -1;
            }
            else if(prev == 2) {//서
                
            }
            else if(prev == 3) {//남

            }
            else if(prev == 4) {//북

            }
        } 
        else if (type == 2) {

        } 
        else if (type == 3) {


        } 
        else if (type == 4) {


        } 
        else if (type == 5) {

        }
    } 
    else {

    }

    return ret;
}

int main() {
    cin >> n >> m;
    ans = n * m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
                --ans;
            if (arr[i][j] == 6)
                vis[i][j] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0)
                continue;
            ans -= solve(i, j, arr[i][j], 0);
        }
    }
}