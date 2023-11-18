#include <bits/stdc++.h>

using namespace std;

long long n, m, k;

vector<pair<long long, long long>> beer;

bool check(int mid) {
    vector<long long> temp;
    long long sum = 0;
    
    for(int i = 0; i < k; i++) {
        if(beer[i].first <= mid) {
            temp.push_back(beer[i].second);
        }
    }
    
    if(temp.size() < n) return true;
    
    sort(temp.begin(), temp.end(), greater<long long>());
        
    for(int i = 0; i < n; i++) {
        sum += temp[i];
    }
    
    if(sum < m) return true;
    else return false;
}

long long binarySearch() {
    long long start = 0;
    long long end = INT_MAX;
    long long mid;
    if(check(end)) return -1;
    while(start + 1 < end) {
        mid = (start + end) / 2;
        
        if(check(mid)) start = mid;
        else end = mid;
    }
    
    
    return end; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++) {
        long long prefer, alc;
        cin >> prefer >> alc;
        
        beer.push_back({alc, prefer});
    }
    
    sort(beer.begin(), beer.end());
    
    cout << binarySearch();
}
