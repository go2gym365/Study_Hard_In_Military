#include<bits/stdc++.h>

using namespace std;

int k, n;
long long ans = 0;

int arr[10001];

int main() {
    cin >> k >> n;
    int maxv = 0;

    for(int i = 0; i < k; i++) {
        cin >> arr[i];
        maxv = max(maxv, arr[i]);
    }

    long long low = 1;
    long long high = maxv;
    long long mid;

    while(low <= high) {
        mid = (low + high) / 2;

        int div = 0;

        for(int i = 0; i < k; i++) {
            div += arr[i] / mid;
        }
        if(div >= n) {
            low = mid + 1;
            ans = max(ans, mid);
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;
}