#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> input;
long long ans = 0;

void solve(long long i) {
    long long start = 0;
    long long end =  n-1;
    while(start < end) {
        if(start == i) {
            start++;
            continue;
        }
        else if(end == i) {
            end--;
            continue;
        }
        
        if(input[start] + input[end] < input[i]) start++;
        else if(input[start] + input[end] == input[i]) {
            ans++;
            return;
        }
        else end--;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        input.push_back(a);
    }
    
    sort(input.begin(), input.end());
    
    for(long long i = 0; i < n; i++) {
        solve(i);
    }
    
    cout << ans;
}
