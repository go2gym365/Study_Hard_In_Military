#include<bits/stdc++.h>

using namespace std;

int n, s;
vector<int> input;
long long ans;
map<int, int> m;

void left(int idx, int sum) {
    if(idx == n / 2) {
        m[sum]++;
        return;
    }
    left(idx+1, sum);
    left(idx+1, sum + input[idx]);
}

void right(int idx, int sum) {
    if(idx == n) {
        ans += m[s - sum];
        return;
    }
    right(idx+1, sum);
    right(idx+1, sum + input[idx]);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> s;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    left(0, 0);
    right(n/2, 0);

    if(s == 0) ans--;
    cout << ans;
}