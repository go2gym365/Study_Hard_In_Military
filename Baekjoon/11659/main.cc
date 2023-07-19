#include<bits/stdc++.h>

using namespace std;

vector<int> num(100001);

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);    
    
    int n, m;
    cin >> n >> m;
    
    num[0] = 0;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        num[i] = num[i - 1] + a;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << num[b] - num[a - 1] << "\n";
    }
}