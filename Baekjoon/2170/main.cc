#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

bool Compare(pair<int, int> A, pair<int, int> B) {
    if (A.first == B.first)
        return A.second < B.second;
    return A.first < B.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    int cnt;
    int temp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end(), Compare);

    cnt = v[0].second - v[0].first;
    temp = v[0].second;

    for (int i = 1; i < n; i++) {
        if (temp < v[i].second && temp >= v[i].first) {
            cnt = cnt + (v[i].second - temp);
        }
        else if (temp < v[i].first) {
            cnt += v[i].second - v[i].first;
        }
        else if(v[i].first <= temp && v[i].second <= temp) continue;
        temp = v[i].second;
    }
    cout << cnt;
}