#include<bits/stdc++.h>

using namespace std;

int n, k;

vector<pair<int, int>> apple;
queue<int> Move;
queue<char> Cmd;

int main() {
    cin >> n >> k;
    int t;
    int ans = 0;

    int curx = 0;
    int cury = 0;

    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

        }
    }*/

    for(int i = 0; i < k; i++) {
        int row, column;
        cin >> row >> column;
        
        apple.push_back({column, row});
    }
    
    Cmd.push('T');

    while(t--) {
        int move;
        char cmd;

        cin >> move >> cmd;

        Move.push(move);
        Cmd.push(cmd);
    }

    while(!Cmd.empty()) {        
        if(Cmd.front() == 'T') {
            ans += Move.front();
            curx += Move.front();
            Move.pop();
            Cmd.pop();
        }
        else if(Cmd.front() == 'D') {
            if(cury + Move.front() > n) {
                ans += n - cury;
                break;
            }
            ans += Move.front();
            cury += Move.front();
            
            Move.pop();
        }
        else if(Cmd.front() == 'F') {
            if(cury + Move.front() > n) {
                ans += n - cury;
                break;
            }
            ans += Move.front();
            curx += Move.front();
            Move.pop();
        }

        
    }
}