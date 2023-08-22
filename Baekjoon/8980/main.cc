#include<bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> vec;
int capacity[2001];

int main() {
    int result = 0;
    int n, c, m;
    cin >> n >> c >> m;

    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        vec.push_back({{to, from}, cost});
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < n; i++) {
        int maxCost = 0;

        for(int j = vec[i].first.second; j < vec[i].first.first; i++) 
            maxCost = max(maxCost, capacity[j]);

        int val = min(vec[i].second, c - maxCost);
        result += val;

        for(int j = vec[i].first.second; j < vec[i].first.first; i++) {
            capacity[j] += val;
        }
    }    
    cout << result;
}