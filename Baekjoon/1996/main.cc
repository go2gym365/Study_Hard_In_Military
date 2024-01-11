#include<bits/stdc++.h>

using namespace std;

int n;

int mine[1001][1001];
int sum[1001][1001];
char ans[1001][1001];

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        
        for(int j = 0; j < n; j++) {
            if(str[j] == '.') {
                mine[i][j] = 0;
            }
            else {
                q.push({i, j});
                mine[i][j] = (str[j]-'0');
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mine[i][j] == 0) continue;
            
            for(int k = 0; k < 8; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                sum[ny][nx] += mine[i][j];
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!q.empty() && q.front().first == i && q.front().second == j) {
                ans[i][j] = '*';
                q.pop();
            }
            else {
                if(sum[i][j] >= 10) {
                    ans[i][j] = 'M';
                }
                else {
                    ans[i][j] = sum[i][j]+'0';
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}