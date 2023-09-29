#include<bits/stdc++.h>

using namespace std;

int n;
int ans[2];
vector<vector<int>> chess(11, vector<int> (11, 0));
int leftDia[20]; //왼쪽 대각선(/)
int rightDia[20]; // 오른쪽 대각선(\)

void solve(int row, int col, int cnt, int color) {
    if(col >= n) {
        row++;
        //체스판은 검은색과 흰색판이 서로 번갈아가면서 나온다
        //항상 2씩 올려주기 때문에 짝수번재 1열에서 시작했으면 홀수 2열에서 시작했으면 짝수가 나온다
        if(col % 2 == 0) col = 1;
        else col = 0;
    }
    if(row >= n) {
        // 색깔별 최대 갯수를 갱신
        ans[color] = max(ans[color], cnt);
        return;
    }

    if(chess[row][col] && !leftDia[col - row + n - 1] && !rightDia[row + col]) {
        leftDia[col - row + n - 1] = rightDia[row + col] = 1;
        solve(row, col + 2, cnt+1, color);
        leftDia[col - row + n - 1] = rightDia[row + col] = 0;
    }
    solve(row, col+2, cnt, color);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> chess[i][j];
        }
    }

    //첫 시작을 1열에서 시작
    solve(0, 0, 0, 0);
    //첫 시작을 2열에서 시작
    solve(0, 1, 0, 1);

    cout << ans[0] + ans[1];
}