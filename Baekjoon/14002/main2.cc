#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> vec;

int dp[1001], len[1001];

void tr(int idx){ // 4
    if(idx == dp[idx]) {
        cout << vec[idx] << " ";
        return;
    }
    tr(dp[idx]);
    cout << vec[idx] << " ";
}

int main() {
    int Max = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
        dp[i] = i;
        len[i] = 1;

        for(int j = 0; j < i; j++) {
            if(vec[j] < vec[i]) {
                if(len[i] < len[j] + 1){
                    len[i] = len[j] + 1;
                    dp[i] = j;
                }
            }
        }
        if(len[i] > len[Max])
            Max = i;
    }
    cout << len[Max] << "\n";
    tr(Max);
}