#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int graph[3][3];
map<string, int> m;

string str = "";
const string answer = "123456780";


int bfs() {
    queue<string> q;
    q.push(str);
    
    while(!q.empty()) {
        string curState = q.front();
        
        q.pop();
        
        if(curState == answer) {
            return  m[curState];
        }
        
        int zero = curState.find('0');
        int x = zero / 3;
        int y = zero % 3;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
            
            string temp = curState;
            
            swap(temp[3*x + y], temp[3*nx+ny]);
            
            if(!m[temp]) {
                m[temp] = m[curState] + 1;
                q.push(temp);
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> graph[i][j];
            str += (graph[i][j] + '0');
        }
    }
    
    cout << bfs();
}