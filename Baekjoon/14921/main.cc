#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> input;
int ans = 0x3f3f3f3f;

void solve() {
    int start = 0;
    int end = n - 1;

    while(start < end) {
        if(start + end == 0) {
            ans = 0;
            return;
        }

        if(abs(input[start] + input[end]) < abs(ans)) {
            ans = input[start] + input[end];
        }

        if(input[start] + input[end] < 0) start++;
        else end--;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        input.push_back(a);
    }
    
    sort(input.begin(), input.end());

    solve();
    cout << ans;
}