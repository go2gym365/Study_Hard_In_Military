#include<bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int ans = 0;

vector<int> v[50001];
vector<int> dist(20001, INF);
vector<int> answer;

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < v[here].size(); ++i) {
            int there = v[here][i];
            int ncost = cost + 1;
            
            if(dist[there] > ncost) {
                dist[there] = ncost;
                pq.push({-ncost, there});
                
                if(dist[there] > ans) {
                    ans = dist[there];
                    answer.clear();
                    answer.push_back(there);
                }
                else if(dist[there] == ncost) answer.push_back(there);
            }            
        }
    }
}

int main() { 
    int N, M;
    cin >> N >> M;

    while(M--) {
        int s, e;
        cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    dijkstra();

    sort(answer.begin(), answer.end());

    cout << answer[0] << " " << ans << " " << answer.size();
}