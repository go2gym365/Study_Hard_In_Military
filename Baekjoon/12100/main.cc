#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> block(21, vector<int> (21, 0));
int maxValue = -0x3f3f3f3f;

void moveBlock(vector<vector<int>> &board, int type) {
    queue<int> q;
    //0좌 1상 2우 3하
    //좌
    if(type == 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j]) {
                    q.push(board[i][j]);
                }
                board[i][j] = 0;
            }

            int idx = 0;

            while(!q.empty()) {
                int num = q.front();
                q.pop();
                if(board[i][idx] == 0) {
                    board[i][idx] = num;
                }
                else if(board[i][idx] == num) {
                    board[i][idx] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    board[i][idx] = num;
                }
            }
        }
    }
    //상
    else if(type == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[j][i]) {
                    q.push(board[j][i]);
                }
                board[j][i] = 0;
            }

            int idx = 0;

            while(!q.empty()) {
                int num = q.front();
                q.pop();
                if(board[idx][i] == 0) {
                    board[idx][i] = num;
                }
                else if(board[idx][i] == num) {
                    board[idx][i] *= 2;
                    idx++;
                }
                else {
                    idx++;
                    board[idx][i] = num;
                }
            }
        }
    }
    //우
    else if(type == 2) {
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if(board[i][j]) {
                    q.push(board[i][j]);
                }
                board[i][j] = 0;
            }

            int idx = n - 1;

            while(!q.empty()) {
                int num = q.front();
                q.pop();
                if(board[i][idx] == 0) {
                    board[i][idx] = num;
                }
                else if(board[i][idx] == num) {
                    board[i][idx] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    board[i][idx] = num;
                }
            }
        }
    }
    //하
    else if(type == 3) {
        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if(board[j][i]) {
                    q.push(board[j][i]);
                }
                board[j][i] = 0;
            }

            int idx = n - 1;

            while(!q.empty()) {
                int num = q.front();
                q.pop();
                
                if(board[idx][i] == 0) {
                    board[idx][i] = num;
                }
                else if(board[idx][i] == num) {
                    board[idx][i] *= 2;
                    idx--;
                }
                else {
                    idx--;
                    board[idx][i] = num;
                }
            }
        }
    }
}

void solve(vector<vector<int>> &board, int cnt) {
    if(cnt == 5) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                maxValue = max(maxValue, board[i][j]);
            }
        }
        return;
    }

    vector<vector<int>> temp = board;

    for(int i = 0; i < 4; i++) {
        moveBlock(board, i);
        solve(board, cnt + 1);
        board = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> block[i][j];
        }
    }

    solve(block, 0);

    cout << maxValue;
}