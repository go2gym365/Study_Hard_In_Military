#include<bits/stdc++.h>

using namespace std;
vector<int> stairs;

int dp[3][301];
int N;
int sum = 0;

int solve(const int n, const int cnt) {
    if(cnt == N) return stairs[cnt];
    if(cnt > N) return -987654321;
    int &ret = dp[n][cnt];
    if(ret != -1) {
        //cout << n << "과" << cnt << "이미 계산되어 리턴함\n";
        return ret;
    }
    ret = 0;
    cout << n << "과" << cnt << "가 처음 계산됨\n";
    // 앞으로 밟을 계단의 수가 0일때
    // 무조건 두 칸 올라가야 됨
    if(n == 0) {
        ret = max(ret, solve(1, cnt + 2) + stairs[cnt]);
    }
    // 두칸을 올라가고 n을 초기화하거나
    // 한칸을 올라가고 다음에 두칸을 뛰어넘던가
    else if(n == 1) {
        ret = max(ret, solve(0, cnt + 1) + stairs[cnt]);
        ret = max(ret, solve(1, cnt + 2) + stairs[cnt]);
    }
    // 시작게단은 계단으로 치지 않기 때문에 n = 2로 설정
    else if(n == 2) {
        ret = max(ret, solve(1, cnt + 1) + stairs[cnt]);
        ret = max(ret, solve(1, cnt + 2) + stairs[cnt]);
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N;
    stairs.push_back(0);
    for(int i = 0; i < N; i++) {
        int j;
        cin >> j;
        stairs.push_back(j);
    }
    cout << solve(2, 0);
}