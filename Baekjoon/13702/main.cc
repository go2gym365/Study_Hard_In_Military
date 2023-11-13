#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, k;

long long maxValue = 0;
long long ans = 0;

vector<long long> drink;

bool check(long long mid) {
    long long cnt = 0;
    for(long long i = 0; i < n; i++) {
        cnt += drink[i] / mid;
    }
    if(cnt >= k) return true;
    else return false;
}

long long binarySearch() {
    long long start = 0;
    long long end = 2147483647;
    long long mid;
    

    while(start + 1 < end) {
        mid = (start + end) / 2;
            
        if(check(mid)) start = mid;
        else end = mid;
    }
    
    return start;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cin.tie(0);
    cin >> n >> k;
    
    for(long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        maxValue = max(maxValue, a);
        drink.push_back(a);
    }
    
    cout << binarySearch();
}
