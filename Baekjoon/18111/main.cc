#include<bits/stdc++.h>

using namespace std;

int n, m, b;

vector<vector<int>> v(501, vector<int>(501, 0));


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cin.tie(0);
    int leastTime = 987654321;
    int mostHeight;
    cin >> n >> m >> b;

    for(int i= 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i <= 256; i++) {
        int build = 0;
        int remove = 0;

        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                int height = v[j][k] - i;
                if(height > 0) remove += height;
                else if(height < 0) build -= height;
            }
        }
        if(remove + b >= build) {
            int time = remove * 2 + build;
            if(leastTime >= time) {
                leastTime = time;
                mostHeight = i;
            }
        }
    }
    cout << leastTime << ' ' << mostHeight;
}