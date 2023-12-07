#include <bits/stdc++.h>

using namespace std;

string input[51];
bool vis[51][51];

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int cnt = 0;
    
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            if(input[i][j] == '-') {
                for(int k = j; k < m; k++) {
                    if(input[i][k] != '-') break;
                    else vis[i][k] = true;
                }
            }
            else if(input[i][j] == '|') {
                for(int k = i; k < n; k++) {
                    if(input[k][j] != '|') break;
                    vis[k][j] = true;
                }
            }
            cnt++;
        }
    }
    
    cout << cnt;
}