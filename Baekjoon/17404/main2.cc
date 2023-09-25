#include<bits/stdc++.h>

using namespace std;

int n;
vector<int>input [1001];
int dp[1001][3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> n;

    for(int i = 0; i < n; i++) {
        int r, g, b;
        cin >> r >> g >> b;

        input[i].push_back(r);
        input[i].push_back(g);
        input[i].push_back(b);
    }

    //첫번째 집의 색깔
    for(int color = 0; color < 3; color++) {
        //1번집의 색깔과 같은 
        for(int i = 0; i < 3; i++) {
            if(color == i) {
                dp[0][i] = input[0][i];
            }
            else {
                dp[0][i] = 987654321;
            }
        }

        for(int j = 2; j < n - 1; j++) {
            
        }
    }
}