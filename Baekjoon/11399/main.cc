#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    int answer = 0;
    int temp = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int time;
        cin >> time;
        v.push_back({i, time});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++) {
        temp += v[i].second;
        answer += temp;
    }

    cout << answer;
}