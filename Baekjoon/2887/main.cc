#include <bits/stdc++.h>

using namespace std;

int parent[100001];
int n;
vector<pair<int, int>> cordinate[3];
vector<pair<int, pair<int, int>>> dist;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool isUnion(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y) return true;
    else return false;
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y) return;
    
    if(x > y) parent[x] = y;
    else parent[y] = x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int x, y, z;
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        
        cordinate[0].push_back({x, i});
        cordinate[1].push_back({y, i});
        cordinate[2].push_back({z, i});
        parent[i] = i;
    }
    
    sort(cordinate[0].begin(), cordinate[0].end());
    sort(cordinate[1].begin(), cordinate[1].end());
    sort(cordinate[2].begin(), cordinate[2].end());
    
    for(int i = 0; i < n-1; i++) {
        dist.push_back({abs(cordinate[0][i].first - cordinate[0][i+1].first), {cordinate[0][i].second, cordinate[0][i+1].second}});
        dist.push_back({abs(cordinate[1][i].first - cordinate[1][i+1].first), {cordinate[1][i].second, cordinate[1][i+1].second}});
        dist.push_back({abs(cordinate[2][i].first - cordinate[2][i+1].first), {cordinate[2][i].second, cordinate[2][i+1].second}});
    }
    
    sort(dist.begin(), dist.end());
    
    int ans = 0;
    
    for(int i = 0; i < dist.size(); i++) {
        if(!isUnion(dist[i].second.first, dist[i].second.second)) {
            ans += dist[i].first;
            merge(dist[i].second.first, dist[i].second.second);
        }
    }
    
    cout << ans;
}