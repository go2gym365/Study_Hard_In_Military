#include<bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> vec;

int n, want;

bool cmp(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b) {
    if(a.first.second > b.first.second) 
        return a.first.second > b.first.second;
    else if(a.first.second == b.first.second) {
        if(a.second.first == b.second.first) {
            if(a.second.second == b.second.second) {
                return a.first.first == want;
            }
            return a.second.second > b.second.second;
        }
        return a.second.first > b.second.first;
    }
    return false;
}

int main() {   
    cin >> n >> want;
    for(int i = 0; i < n; i++) {
        int num, gold, silver, copper;

        cin >> num >> gold >> silver >> copper;

        vec.push_back({{num, gold}, {silver, copper}});
    }

    sort(vec.begin(), vec.end(), cmp);

    for(int i = 0; i < n; i++) {
        if(vec[i].first.first == want) {
            cout << i + 1;
        }
    }
}