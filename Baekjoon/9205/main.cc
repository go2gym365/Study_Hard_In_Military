#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        queue<pair<int, int>> q;
        vector<pair<int, int>> cvs;
        vector<bool> vis(101, false);
        pair<int, int> home, festival;
        int n;
        
        cin >> n;
        cin >> home.second >> home.first;

        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            cvs.push_back({y, x});
        }
        cin >> festival.second >> festival.first;

        q.push({home.first, home.second});

        bool isHappy = false;

        while(!q.empty()) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();

            for(int i = 0; i < cvs.size(); i++) {
                if((abs(cvs[i].second - x) + abs(cvs[i].first - y)) > 1000) continue;
                if(vis[i]) continue;
                vis[i] = true;
                q.push({cvs[i].first, cvs[i].second});
            }

            if((abs(festival.second - x) + abs(festival.first - y)) <= 1000) {
                isHappy = true;
                break;
            }
        }

        if(isHappy) cout << "happy\n";
        else cout << "sad\n";
    }    
}