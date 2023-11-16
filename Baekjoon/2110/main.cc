#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, m;
//long long maxDist = 0;

vector<long long> wifi;

bool check(long long mid) {
    long long prev = wifi[0];
    long long cnt = 1;
    
    for(long long i = 1; i < n; i++) {
        long long cur = wifi[i];
        if(cur - prev >= mid) {
            prev = cur;
            cnt++;
        }
    }
    
    if(cnt >= m) return true;
    else return false;
}

long long binarySearch() {
    long long start = 0;
    long long end = 1000000001;
    long long mid;
    
    if(end - start == 1) return 1;
    if(n == m) {
        int prev = wifi[0];
        int maxV = 0;
        for(int i = 1; i < n; i++) {
            if(wifi[i] - prev > maxV) {
                maxV = wifi[i] - prev;
            }
            prev = wifi[i];
        }
        return maxV;
    }
    
    while(start + 1 < end) {
        mid = (start + end) / 2;
        
        if(check(mid)) start = mid;
        else end = mid;
    }
    
    return start;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        //if(maxDist < a) maxDist = a;
        wifi.push_back(a);
    }
    
    sort(wifi.begin(), wifi.end());
    
    cout << binarySearch();
}
