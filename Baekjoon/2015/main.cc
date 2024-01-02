#include <bits/stdc++.h>

using namespace std;

long long n, k;

long long parr[200001];

map<long long, long long> sub;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    
    long long cnt = 0;
    
    for(int i = 1; i <= n; i++) {
        cin >> parr[i];
        parr[i] += parr[i-1];
    }
    
    for(int i = 1; i <= n; i++) {
        if(parr[i] == k) cnt++;
        
        cnt += sub[parr[i] - k];
        
        sub[parr[i]]++;
    }
    
    cout << cnt;
}