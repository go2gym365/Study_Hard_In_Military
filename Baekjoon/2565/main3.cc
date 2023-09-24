#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> input;
vector<int> lis;
int cnt = 0;

int binarySearch(int key) {
    int left = 0;
    int right = lis.size() - 1;
    int mid;

    while(left < right) {
        mid = (left + right) / 2;

        if(key > lis[mid]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return right;
}

void solve() {
    for(int i = 0; i < n; i++) {
        if(lis.empty() || lis.back() < input[i].second) {
            lis.push_back(input[i].second);
            cnt++;
        }
        else {
            int idx = binarySearch(input[i].second);
            //int idx = lower_bound(lis.begin(), lis.end(), input[i].second) - lis.begin();
            lis[idx] = input[i].second;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        input.push_back({a, b});
    }

    sort(input.begin(), input.end());

    solve();

    cout << n - cnt << "\n";
}