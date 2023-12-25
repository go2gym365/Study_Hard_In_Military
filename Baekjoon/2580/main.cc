#include <bits/stdc++.h>

using namespace std;

int sudoku[10][10];
bool numberVis[10];
int zero, solveCnt;

void init(int y, int x) {
    int startX = x - x%3;
    int startY = y - y%3;
    
    for(int i = 0; i < 10; i++) numberVis[i] = false;
    for(int i = 0; i < 9; i++) {
        numberVis[sudoku[i][x]] = true;
        numberVis[sudoku[y][i]] = true;
    }
    for(int i = startY; i < startY + 3; i++) {
        for(int j = startX; j < startX + 3; j++) {
            numberVis[sudoku[i][j]] = true;
        }
    }
}

bool availableNumCheck(int y, int x, int k) {
    int startX = x - x%3;
    int startY = y - y%3;
    
    //세로 확인
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][x] == k) return false;
    }
    //가로확인
    for(int i = 0; i < 9; i++) {
        if(sudoku[y][i] == k) return false;
    }
    //3*3 확인
    for(int i = startY; i < startY + 3; i++) {
        for(int j = startX; j < startX + 3; j++) {
            if(sudoku[i][j] == k) return false;
        }
    }
    return true;
}

bool solve(int n) {
    if(solveCnt == zero) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << "\n";
        }
        return true;
    }
    
    int i = n / 9;
    int j = n % 9;
    
    if(sudoku[i][j] == 0) {
        for(int k = 1; k <= 9; k++) {
            init(i, j);
            
            if(!numberVis[k] && availableNumCheck(i, j, k)) {
                sudoku[i][j] = k;
                numberVis[k] = true;
                solveCnt++;
                if(solve(n+1)) return true;
                sudoku[i][j] = 0;
                numberVis[k] = false;
                solveCnt--;
            }
        }
    }
    else return solve(n+1);
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) zero++;
        }
    }
    
    solve(0);
}