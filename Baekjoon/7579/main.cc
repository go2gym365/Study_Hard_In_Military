#include<bits/stdc++.h>

using namespace std;

int n, m;
int accum = 0;

int active[101];
int value[101];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> active[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> value[i];
        accum += value[i];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = accum; j >= value[i]; j--) {
            dp[j] = max(dp[j], dp[j-value[i]] + active[i]);
        }
    }
    
    for(int i = 0; i <= accum; i++) {
        if(dp[i] >= m) {
            cout << i;
            break;
        }
    }    
}