#include<bits/stdc++.h>

using namespace std;

string input[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int lowCnt = 0;
    
    //가로로 확인
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(input[i][j] == '.') cnt++;
            else {
                if(cnt >= 2) {
                    lowCnt++;
                }
                cnt = 0;
            }
        }
        if(cnt >= 2) lowCnt++;
    }
    
    int colCnt = 0;
    
    //세로로 확인
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(input[j][i] == '.') cnt++;
            else {
                if(cnt >= 2) {
                    colCnt++;
                }
                cnt = 0;
            }
        }
        if(cnt >= 2) colCnt++;
    }
    
    cout << lowCnt << ' ' << colCnt;
}