#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m;

vector<long long> arr;
vector<long long> brr;

long long binarySearch(long long target) {
    long long start = 0;
    long long end = m-1;
    long long mid;
    
    while(start + 1 < end) {
        mid = (start + end) / 2;
        
        if(brr[mid] < target) {
            start = mid;
        }
        else {
            end = mid;
        }
    }
    
    if(abs(target - brr[start]) <= abs(target - brr[end])) return brr[start];
    else return brr[end];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        arr.clear();
        brr.clear();
        
        cin >> n >> m;
        for(long long i = 0; i < n; i++) {
            long long a;
            cin >> a;
            arr.push_back(a);
        }
        
        for(long long i = 0; i < m; i++) {
            long long a;
            cin >> a;
            brr.push_back(a);
        }
        
        sort(brr.begin(), brr.end());
        
        long long sum = 0;
        
        for(long long i = 0; i < n; i++) {
            sum += binarySearch(arr[i]);    
        }
        cout << sum << "\n";
    }
}
