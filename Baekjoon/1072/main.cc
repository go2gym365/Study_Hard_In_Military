#include<bits/stdc++.h>

using namespace std;

long long x, y;
long long ex;
bool check(int mid) {
    long long res = (y + mid) * 100 / (x + mid);
    
    if(ex != res) return true;
    else return false;
}

long long solve() {
    long long start = 0;
    long long end = 1000000000;
    long long mid;
    
    if(!check(end)) return -1;
    
    while(start + 1 < end) {
        mid = (start + end) / 2;

        if(check(mid)) end = mid;
        else start = mid;
    }
    
    return end;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> x >> y;
    ex = y * 100 / x;
    
    cout << solve();
}
