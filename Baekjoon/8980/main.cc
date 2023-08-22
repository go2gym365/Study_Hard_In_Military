#include<bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> vec;
int capacity[2001];

int main() {
    int n, c, m;
    cin >> n >> c >> m;

    for(int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;

        vec.push_back({{to, from}, cost});
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i < n; i++) {
        i
    }    
}