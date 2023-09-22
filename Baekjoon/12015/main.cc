#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> input;
vector<int> lis;

int binarySearch(int key) {
    int start = 0;
    int end = lis.size() - 1;

    int mid;

    while(start < end) {
        mid = (start + end) / 2;
        if(key > lis[mid]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return end;
}

void solve() {
    int cnt = 1;
    lis.push_back(input[0]);

    for(int i = 1; i < n; i++) {
        if(lis.back() < input[i]) {
            lis.push_back(input[i]);
            cnt++;
        }
        else {
            int idx = binarySearch(input[i]);
            lis[idx] = input[i];
        }
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        input.push_back(a);
    }

    solve();
}