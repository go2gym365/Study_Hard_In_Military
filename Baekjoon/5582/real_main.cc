#include <bits/stdc++.h>

using namespace std;

string str1, str2;

int ans;
int dp[4001][4001];

int main(){
    cin >> str1 >> str2;
  
    for(int i = 0; i < str1.size(); i++){
        for(int j = 0; j < str2.size(); j++){
            if(str1[i] == str2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
                ans = max(ans,dp[i+1][j+1]);
            }
        }
    }
    cout << ans << '\n';
}
