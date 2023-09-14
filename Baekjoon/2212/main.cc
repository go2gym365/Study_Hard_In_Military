#include<bits/stdc++.h>

using namespace std;

vector<int> sensor;
vector<int> dist;

int main() {
    int answer = 0;
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sensor.push_back(a);
    }

    sort(sensor.begin(), sensor.end());

    for(int i = 0; i < n - 1; i++) {
        dist.push_back(sensor[i + 1] - sensor[i]);
    }

    sort(dist.begin(), dist.end());

    for(int i = 0; i < n - k; i++) {
        answer += dist[i];
    }

    cout << answer;
}