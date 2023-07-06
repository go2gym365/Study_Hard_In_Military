#include<bits/stdc++.h>

using namespace std;

int n, m;
int res = 0;
string str;

queue<char> q;

int main() {
    cin >> n >> m >> str;

    for(int i = 0; i < m; i++) {
        if(str[i] == 'O') continue;
        int cnt = 0;
        while(str[i + 1] == 'O' && str[i + 2] == 'I') {
            cnt++;
            i += 2;
            if(cnt == n) {
                cnt--;
                res++;
            }
        }
    }

    cout << res;
}