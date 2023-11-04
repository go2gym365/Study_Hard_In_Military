#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;


int input[2200][2200];

int zeroCnt = 0;
int minusCnt = 0;
int plusCnt = 0;

void solve(int y, int x, int size) {
    bool check = false;
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(input[y][x] != input[i][j]) {
                check = true;
                break;
            }
        }
        if(check) break;
    }
    
    if(check) {
       solve(y, x, size / 3);
       solve(y, x + size / 3, size / 3);
       solve(y, x + 2*(size / 3), size/3);
       
       solve(y + size / 3, x, size/3);
       solve(y + size / 3, x + size / 3, size / 3);
       solve(y + size / 3, x + 2*(size / 3), size / 3);
       
       solve(y + 2*(size / 3), x, size / 3);
       solve(y + 2*(size / 3), x + size / 3, size / 3);
       solve(y + 2*(size / 3), x + 2*(size / 3), size / 3);
    }
    else {
        if(input[y][x] == 1) {
            plusCnt++;
        }
        else if(input[y][x] == 0) {
            zeroCnt++;
        }
        else if(input[y][x] == -1) {
            minusCnt++;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> input[i][j];
        }
    }
    
    solve(0, 0, n);
    
    cout << minusCnt << "\n" << zeroCnt << "\n" << plusCnt;
}
