#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;

vector<int> tree[100001];
int check[100001];

void solve(int cur, int prev) {
    check[cur] = prev;
    for(int i = 0; i < tree[cur].size(); i++) {
        if(check[tree[cur][i]] != -1) continue;

        solve(tree[cur][i], cur);

    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(check, -1, sizeof(check));
    cin >> n;
    
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    solve(1, 0);
    
    for(int i = 2; i <= n; i++) {
        cout << check[i] << "\n";
    }
}
