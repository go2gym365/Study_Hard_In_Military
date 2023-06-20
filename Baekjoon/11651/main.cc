#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}