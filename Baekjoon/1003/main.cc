#include<bits/stdc++.h>

using namespace std;

int dp[40];

int Fibo(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int &ret = dp[n];
    if(ret != -1) return ret;
    ret = 0;
    
    ret = Fibo(n - 1) + Fibo(n - 2);
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if(temp == 0) cout << '1' << " " << '0';
        else cout << Fibo(temp - 1) << " " << Fibo(temp) << "\n";
    }
}