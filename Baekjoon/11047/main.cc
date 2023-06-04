#include<bits/stdc++.h>

using namespace std;

vector<int> Cost;

int main() {
    int n, k;
    int cnt = 0;

    cin >> n >> k;

    while(n--) {
        int cost;
        cin >> cost;
        Cost.push_back(cost);
    }

    for(int i = Cost.size() - 1; i >= 0; i--) {
        if(k == 0) break;
        cnt += k / Cost[i];
        k %= Cost[i];
    }
    cout << cnt;
}