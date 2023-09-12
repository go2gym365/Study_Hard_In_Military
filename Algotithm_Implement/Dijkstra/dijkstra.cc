#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; // 시작 노드에서 해당 노드까지의 경로가 없는 경우의 비용
#define MAX_VERTEX 1001 // 최대 vertex 개수
#define MAX_EDGE 1001 // 최대 edge 개수

int v, e, start_node;

//최소 비용 배열
int d[MAX_VERTEX];

//간선 정보를 담은 vector
//index : 시작노드
//value : pair<비용, 도착 노드> 목록
vector<pair<int, int>> edge[MAX_EDGE];

void dijkstra(int start_node) {
    //시작 노드에서 시작 노드로 가는 비용은 0
    d[start_node] = 0;

    //시작 노드부터 어떤 도착 노드까지의 최소 비용을 제시하는 간선 목록
    //pair<비용, 도착 노드> 형식의 우선순위 큐이다.
    priority_queue<pair<int, int>> pq;

    //시작 노드에서 시작 노드로 가는 경로와 비용을 pq에 삽입;
    pq.push({0, start_node});

    //pq의 모든 경로를 확인할 때 까지 반복
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = -pq.top().first; //오름차순 정렬을 위해 -를 붙혀서 넣어줬기 때문에 다시 원래값으로 돌림

        pq.pop();

        if(d[cur] < cost) {
            continue;
        }

        for(int i = 0; i < edge[cur].size(); ++i) {
            int next = edge[cur][i].second;
            int nextCost = cost + edge[cur][i].first;
            if(d[next] > nextCost) {
                d[next] = nextCost;
                pq.push({-nextCost, next}); //오름차순 정렬을 위해 -를 붙혀서 넣어줌
            }
        }
    }
}

int main() {
    cin >> v >> e;
    cin >> start_node;

    for(int i = 1; i <= v; i++) {
        d[i] = INF;
    }

    while(e--) {
        int start, end, cost;
        cin >> start >> end >> cost;   

        edge[start].push_back({cost, end});
    }

    dijkstra(start_node);

    for(int i = 1; i < v + 1; ++i) {
        if(d[i] == INF) {
            cout << "INF" << "\n";
        }
        else {
            cout << d[i] << "\n";
        }
    }
}