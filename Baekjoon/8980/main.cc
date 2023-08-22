#include<bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> vec;
int capacity[2001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int result = 0;
    int n, c, m;
    cin >> n >> c >> m;

    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        vec.push_back({{to, from}, cost});
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < m; i++) {
        int maxValue = 0;

        int from = vec[i].first.second;
        int to = vec[i].first.first;
        int cost = vec[i].second;

        for(int j = from; j < to; j++) {
            maxValue = max(capacity[j], maxValue);
        }
        
        int left = min(cost, c-maxValue);
        result += left;

        for(int j = from; j < to; j++) {
            capacity[j] += left;
        }
    }
    cout << result;
}