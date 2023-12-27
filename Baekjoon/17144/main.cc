#include <bits/stdc++.h>

using namespace std;

int r, c, t;

int dusts[51][51];
int sumTemp[51][51];

int airCleaner[2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void topSideCleaner() {
    int airY = airCleaner[0];
    
    for(int i = airY-1; i > 0; i--) {
        dusts[i][0] = dusts[i-1][0];
    }
    for(int i = 0; i < c-1; i++) {
        dusts[0][i] = dusts[0][i+1];
    }
    for(int i = 0; i < airY; i++) {
        dusts[i][c-1] = dusts[i+1][c-1];
    }
    for(int i = c-1; i > 0; i--) {
        if(i == 1) dusts[airY][i] = 0;
        else dusts[airY][i] = dusts[airY][i-1];
    }
}

void downSideCleaner() {
    int airY = airCleaner[1];
    
    for(int i = airY+1; i < r-1; i++) {
        dusts[i][0] = dusts[i+1][0];
    }
    for(int i = 0; i < c-1; i++) {
        dusts[r-1][i] = dusts[r-1][i+1];
    }
    for(int i = r-1; i > airY; i--) {
        dusts[i][c-1] = dusts[i-1][c-1];
    }
    for(int i = c-1; i > 0; i--) {
        if(i == 1) dusts[airY][i] = 0;
        else dusts[airY][i] = dusts[airY][i-1];
    }
}

int start() {
    while(t--) {
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(dusts[i][j] <= 0) continue;
                
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                    int ndx = j + dx[k];
                    int ndy = i + dy[k];
                    if(ndx < 0 || ndx >= c || ndy < 0 || ndy >= r) continue;
                    if(dusts[ndy][ndx] == -1) continue;
                    
                    cnt++;
                    sumTemp[ndy][ndx] += dusts[i][j] / 5;
                }
                dusts[i][j] -= ((dusts[i][j]/5)*cnt);
            }
        }
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                dusts[i][j] += sumTemp[i][j];
                sumTemp[i][j] = 0;
            }
        }
        
        topSideCleaner();
        downSideCleaner();
    }
    int sum = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(dusts[i][j] <= 0) continue;
            sum += dusts[i][j];
        }
    }
    
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> r >> c >> t;
    
    int cnt = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> dusts[i][j];
            if(dusts[i][j] == -1) {
                airCleaner[cnt] = i;
                cnt++;
            }
        }
    }
    
    cout << start();
}