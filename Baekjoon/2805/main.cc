#include<bits/stdc++.h>

using namespace std;

int n, m;
int ans = 0;
long long sum = 0;

vector<int> vec;

void binarySearch(int left, int right) {
    while(left <= right) {
        int mid = (left + right) / 2;
        sum = 0;

        for(int i = 0; i < n; i++) {
            if(mid < vec[i]) sum += vec[i] - mid;
        }
        if(sum >= m) {
            if(ans < mid) ans = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int maxNum = -9876554;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
        if(maxNum < a) maxNum = a;
    }

    binarySearch(0, maxNum);

    cout << ans;
}