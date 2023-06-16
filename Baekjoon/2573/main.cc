#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v(301, vector<int>(301, 0));
vector<vector<int>> cntv(301, vector<int>(301, 0));
vector<vector<bool>> vis(301, vector<bool>(301, false));

int n, m, result = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void DFS(int yy, int xx, int cnt) {
    cntv[yy][xx] = cnt;

    for(int i = 0; i < 4; i++) {
        int nx = xx + dx[i];
        int ny = yy + dy[i];

        if (ny >= 0 && ny < n && nx >= 0 && nx < m)
			if (v[ny][nx] && cntv[ny][nx] == 0) 
				DFS(ny, nx, cnt);
    }
}

void melt_ice() {
    int melt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 0) continue;
            melt = 0;
            for(int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];
                if (v[ny][nx] == 0 && ny >= 0 && ny < n && nx >= 0 && nx < m)
                    melt++;
            }

            if(v[i][j] < melt) continue;
            else cntv[i][j] == v[i][j] - melt;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            v[i][j] = cntv[i][j];
    }    
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    while(1) {
        //빙산이 몇조각인지 확인하기
        fill(cntv.begin(), cntv.end(), vector<int> (301, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; i < m; j++) {
                if(v[i][j] && cntv[i][j] == 0) {
                    cnt++;
                    DFS(i, j, cnt);
                }
            }
        }
        // 2. 두조각 이상인지 확인하기
        if(cnt >= 2) {
            cout << result << "\n";
            return 0;
        }

        //3. 얼음 녹이기
        fill(cntv.begin(), cntv.end(), vector<int>(301, 0));
        melt_ice();

        // 3. 얼음이 다 녹은지 확인
        bool jud = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j]) jud = true;
            }
        }
        if(jud == false) {
            cout << 0 << "\n";
            return 0;
        }

        //카운트 추가
        result++;
    }
}