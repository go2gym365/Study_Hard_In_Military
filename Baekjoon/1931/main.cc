#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>>v;

int main() {
    int n;
    int cnt = 0;
    int time = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int begin, end;
        cin >> begin >> end;
        v.push_back({end, begin});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        if(time <= v[i].second) {
            cnt++;
            time = v[i].first;
        }
    }

    cout << cnt;
}