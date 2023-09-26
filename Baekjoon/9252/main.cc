#include<bits/stdc++.h>

using namespace std;

string str1, str2;
int dp[1001][1001];
char trace[1001];

int solve(int s1, int s2) {
    if(s1 == str1.size() || s2 == str2.size()) return 0;
    int &ret = dp[s1][s2];
    if(ret != 0) return ret;

    ret = 1;

    ret = max(ret, solve(s1 + 1, s2));
    ret = max(ret, solve(s1, s2 + 1));

    if(str1[s1] == str2[s2]) {
        int temp = ret;
        ret = max(ret, solve(s1 + 1, s2 + 1) + 1);
        if(temp < ret) {
            trace[]
        }
    }

    return ret;
}

/*void print() {
    vector<char> trace;
    int s1 = str1.length(); 
    int s2 = str2.length();

    while(s1 != 0 && s2 != 0) {
        if(dp[s1][s2] == dp[s1 - 1][s2])
            s1--;
        else if(dp[s1][s2] == dp[s1][s2 - 1])
            s2--;
        else {
            trace.push_back(str1[s1-1]);
            s1--;
            s2--;
        }
    }

    for(int i = trace.size() - 1; i >= 0; i--) {
        cout << trace[i];
    }
}*/

void find(int s1, int s2){
    if(s1 == str1.length() || s2 == str2.length()) return;

    if(str1[s1] == str2[s2] && )
}

int main() {
    memset(dp, 0, sizeof(dp));
    cin >> str1 >> str2;

    cout << solve(0, 0) << "\n";

    //print();
    find(0, 0);
}