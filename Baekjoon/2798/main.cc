#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    int n, m;
    int temp = -987654321;
    int ans = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                temp = v[i] + v[j] + v[k];
                if(temp > m) continue;
                ans = max(temp, ans);
            }
        }
    }
    cout << ans;
}