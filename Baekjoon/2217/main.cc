#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    int n;
    cin >> n;
    int ans = -987654321;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        ans = max(ans, (n - i) * v[i]);
    }
    cout << ans;
}