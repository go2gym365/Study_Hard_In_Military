#include <iostream>
#include <stack>

using namespace std;

bool vis[51];

int solve(string &str, int idx) {
    int cnt = 0;
    
    for(int i = idx; i < str.length(); i++) {
        if(str[i] == '(' && !vis[i]) {
            vis[i] = true;
            int num = str[i - 1] - '0';
            cnt--;
            cnt += num * solve(str, i + 1);
        }
        else if(str[i] == ')' && !vis[i]) {
            vis[i] = true;
            return cnt;
        }
        else if(!vis[i]) {
            vis[i] = true;
            cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    
    cin >> str;
    
    cout << solve(str, 0);

    return 0;
}
