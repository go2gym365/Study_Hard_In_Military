#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long n, m;
long long sum = 0;
vector<long long> course;

bool check(long long mid) {
    long long chSum = 0;
    long long cnt = 1;
    
    for(long long i = 0; i < n; i++) {
        if(course[i] <= mid) {
            chSum += course[i];
        }
        else return false;
        
        if(chSum + course[i+1] > mid) {
            if(cnt + 1 > m) return false;
            cnt++;
            chSum = 0;
        }
    }
    return true;
}

long long binarySearch() {
    long long start = 0;
    long long end = sum;
    long long mid;
    
    while(start + 1 < end) {
        mid = (start + end) / 2;
        
        if(check(mid)) end = mid;
        else start = mid;
    }
    
    return end;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        sum += a;
        course.push_back(a);
    }
    
    cout << binarySearch();
}
