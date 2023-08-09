#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> vec;

int solve(int sum) {
    int ret = 0;
    if(sum == 10) return 1;
    if(sum > 10) return 0;

    for(int i = 0; i < n; i++) {
        ret += solve(sum + vec[i]);
    }
    return ret;
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    cout << solve(0);
}