#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> card;
map<int, bool> Map;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        Map.insert({a, true});
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if(Map[a]) cout << 1 << " ";
        else cout << 0 << " ";
    }
}