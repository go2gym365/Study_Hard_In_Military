#include<bits/stdc++.h>

using namespace std;

int N, r, c;
int ans = -1;
int cnt = 0;

void solve(int x, int y, int move) {
    if(ans != -1) return;
    if(x == r && y == c) {
        ans = cnt;
        return;
    }
    if(move == 0) {
        ++cnt;
        return;
    }

    if(c >= x && c < x + move && r >= y && r < y + move) {
        solve(x, y, move / 2);
    }
}

int main() {
    cin >> N >> r >> c;

    int start = pow(2, N) / 2;

    solve(0, 0, start);
}