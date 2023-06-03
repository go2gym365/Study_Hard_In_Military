#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), cmp);

    for(auto a : v) {
        cout << a.first << " " << a.second << "\n";
    }
}