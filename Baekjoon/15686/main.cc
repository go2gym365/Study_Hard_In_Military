#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> home;
vector<pair<int, int>> kfc;
vector<pair<int, int>> pick;
bool choice[13];
int answer = 0x3f3f3f3f;

int n, m;

int calcDist(pair<int, int> p, pair<int, int> h) {
    return abs(p.first - h.first) + abs(p.second - h.second);
}

void solve() {
    int temp = 0;

    for(int i = 0; i < home.size(); i++) {
        int minDist = 0x3f3f3f3f;
        for(int j = 0; j < pick.size(); j++) {
            minDist = min(minDist, calcDist(pick[j], home[i]));
        }
        temp += minDist;
    }
    answer = min(answer, temp);
}

void combination(int k, int cnt) {
    if(cnt == m) {
        solve();
    }

    for(int i = k; i < kfc.size(); i++) {
        if(choice[i]) continue;

        choice[i] = true;
        pick.push_back({kfc[i].first, kfc[i].second});
        combination(i, cnt+1);
        choice[i] = false;
        pick.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int input;
            cin >> input;
            if(input == 1) home.push_back({i, j});
            else if(input == 2) kfc.push_back({i, j});
        }
    }

    combination(0, 0);

    cout << answer;
}