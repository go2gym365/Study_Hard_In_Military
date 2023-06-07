#include<bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, string>>> v;

bool cmp(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
    if(a.second.first == b.second.first) return a.first < b.first;
    return a.second.first < b.second.first;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        string b;
        cin >> a >> b;

        v.push_back({i, {a, b}});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << v[i].second.first << " " << v[i].second.second << "\n";
    }
}