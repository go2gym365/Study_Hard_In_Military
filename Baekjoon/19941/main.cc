#include <iostream>

using namespace std;

string str;
int n, k;
int ans = 0;

int vis[20001];

int main()
{
    cin >> n >> k;
    cin >> str;
    
    for(int i = 0; i < n; i++) {
        if(str[i] != 'P') continue;
        
        for(int j = i - k; j <= i + k; j++) {
            if(!vis[j] && str[j] == 'H') {
                vis[j] = true;
                ans++;
                break;
            }
        }
    }
    
    cout << ans;
}
