#include<bits/stdc++.h>

using namespace std;

struct cmp{
    bool operator() (pair<int, int> a, pair<int, int> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
    int n, k;
    int sum = 0;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;

        pq.push({w, v});
    }

    for(int i = 0; i < n; i++) {
        if()
    }
}