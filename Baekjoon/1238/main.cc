#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
//최소 비용 배열
int d[1001];

vector<pair<int, int>> Edge[10001];

void dijkstra(int start_node) {
    d[start_node] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push({0, start_node});

    while(!pq.empty()) {
        int current = pq.top().second;
        int start_to_current_distance = -pq.top().first;
        pq.pop();

        if(d[current] < start_to_current_distance) continue;

        for(int i = 0; i < Edge[current].size(); i++) {
            int next = Edge[current][i].second;
            int start_to_next_distance = start_to_current_distance + Edge[current][i].first;

            if(d[next] > start_to_next_distance) {
                d[next] = start_to_next_distance;
                pq.push({-start_to_next_distance, next});
            }
                
        }
    }
}

int main() {
    int vertex, edge, end;
    cin >> vertex >> edge >> end;

    for(int i = 1; i <= vertex; ++i) {
        d[i] = INF;
    }

    while(edge--) {
        int s, e, c;
        cin >> s >> e >> c;
        Edge[s].push_back({c, e});
    }

    dijkstra(end);






    int arr[1001];

    for(int i=1; i<=vertex; i++) {
        arr[i] = d[i];
    }

    for(int i=1; i<=vertex; i++) {
        for(int j=1; j<=vertex; j++) d[j] = INF;
        dijkstra(i);
        arr[i] += d[end];
    }

    sort(arr + 1, arr + vertex + 1, greater<>());
    cout << arr[1];
}