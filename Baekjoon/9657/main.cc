#include <cstring>
#include <iostream>

using namespace std;

int n;
const int INF = 987654321;
// 0이면 sk 1이면 cy
int dp[1001];

// 상근이가 이기는 경우는 1, 아닌 경우는 0으로 표시
int solve(int stones) {
    if(stones == 0) return 0;
    if(stones == 1) return 1;
    if(stones == 2) return 0;
    if(stones == 3) return 1;

    int &ret = dp[stones];
    if(ret != -1) return ret;

    ret = !solve(stones - 1) || !solve(stones - 3) || !solve(stones - 4);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    
    if(solve(n)) cout << "SK";
    else cout << "CY";
}
