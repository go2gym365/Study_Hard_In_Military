#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

bool vis[100][100];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    
    int cnt = 0;
    
    while(t--) {
        int x, y;
        cin >> x >> y;
        
        for(int i = y; i < y+10; i++) {
            for(int j = x; j < x+10; j++) {
                vis[i][j] = true;
            }
        }
        
        
    }
    
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(vis[i][j]) cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}
