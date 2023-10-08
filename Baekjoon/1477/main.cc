#include<bits/stdc++.h>

using namespace std;

int n, m, l;
priority_queue<int> pq;
vector<int> input;

int main() {
    cin >> n >> m >> l;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    sort(input.begin(), input.end());

    int prev = 1;
    for(int i = 0; i < n; i++) {
        pq.push(input[i]-prev);
        prev = input[i];
    }
    pq.push(l - 1 - prev);



    for(int i = 0; i < m; i++) {
        int temp = pq.top();
        pq.pop();
        pq.push(temp/2);
        pq.push(temp - (temp/2));
    }

    cout << pq.top();
}