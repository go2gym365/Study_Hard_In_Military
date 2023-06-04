#include<bits/stdc++.h>

using namespace std;

vector<int> Cost = {500, 100, 50, 10, 5, 1};

int main() {
    int val, cnt = 0;
    cin >> val;

    val = 1000 - val;

    for(int i = 0; i < Cost.size(); i++) {
        if(val == 0) break;

        cnt += val / Cost[i];
        val %= Cost[i];
    }
    cout << cnt;
}