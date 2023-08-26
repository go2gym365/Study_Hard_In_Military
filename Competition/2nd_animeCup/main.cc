#include <bits/stdc++.h>

using namespace std;

int dp[3000001];
int isPrime[3000001];
int p;

void checkPrime() {
    for (int i = 2; i <= p; i++) {
        isPrime[i] = i;
    }
    for (int i = 2; i <= p; i++) {
        if (isPrime[i] == 0)
            continue;

        for (int j = 2 * i; j <= p; j += i) {
            isPrime[j] = 0;
        }
    }
}

int solve(int cur) {
    int &ret = dp[cur];
    if(ret != -1) return ret;
    ret = 0;

    int next = cur - 1;

    for(int i = next / 2; i <= next; i++) {
        if(isPrime[i] != 0 && isPrime[next - i] != 0) {
            ret = max(ret, solve(i) + solve(next - i) + 2);
            break;
        }
    }
    return ret;
}

int main() { 
    memset(dp, -1, sizeof(dp));
    cin >> p;
    checkPrime();
    cout << solve(p) + 1;
}