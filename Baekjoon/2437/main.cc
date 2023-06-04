#include<bits/stdc++.h>

using namespace std;


vector<int> v;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        v.push_back(m);
    }

    sort(v.begin(), v.end());

    int res = 1;

    for(int i = 0; i < n; i++){
        if(v[i] > res) break;

        res += v[i];
    }

    cout << res;
}