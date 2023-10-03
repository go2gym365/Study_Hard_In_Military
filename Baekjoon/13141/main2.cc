#include<bits/stdc++.h>

using namespace std;

int n, m;
const int INF = 0x3f3f3f3f;

vector<vector<int>> graph(201, vector<int> (201, -1));
//최단거리 배열
vector<vector<int>> dist(201, vector<int> (201, INF));

double burn() {
    double shortestTime = INF;
    double longestTime, spentTime, remainLen;
    int longestEdge;

    for(int start=1; start <= n; ++start) {
        //start 정점부터 태웠을 때 마지막 간선이 사라지는 시간
        longestTime = 0;

        for(int from = 1; from <= n; ++from) {
            for(int to = 1; to <= n; ++to) {
                longestEdge = graph[from][to];

                if(longestEdge != -1) { // from정점과 간선으로 연결되지 않은 경우
                    remainLen = longestEdge - (dist[start][to] - dist[start][from]);

                    //양쪽 끝에서 불이 붙은 경우
                    if(remainLen > 0) {
                        spentTime = (remainLen / 2) + dist[start][to];
                        longestTime = max(spentTime, longestTime);
                    }
                }
            }
        }
        shortestTime = min(longestTime, shortestTime);
    }
    return shortestTime;
}

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for(int i = 0; i < m; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        //동일한 위치로 가는 간선일 때는 제일 선분만 있으면 됨.
        dist[s][e] = min(dist[s][e], l);
        dist[e][s] = dist[s][e];

        graph[s][e] = max(graph[s][e], l);
        graph[e][s] = graph[s][e];
    }

    //플로이드로 최단거리 구하기
    floyd();

    cout << fixed;
    cout.precision(1);
    cout << burn();
}