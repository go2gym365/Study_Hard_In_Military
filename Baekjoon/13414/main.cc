#include <bits/stdc++.h>

using namespace std;

int n, m;

unordered_map<string, int> um;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        
        um[str] = i;
    }
    
    vector<pair<string, int>> temp;
    
    for(auto & a : um) {
        temp.push_back(a);
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for(int i = 0; i < min(n, (int)temp.size()); i++) {
        cout << temp[i].first << "\n";
    }
}
