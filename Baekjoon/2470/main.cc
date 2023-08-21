#include<bits/stdc++.h>

using namespace std;

const long long INF = 1e12;
vector<long long> ans(2);
vector<long long> vec;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    
    long long n;
    cin >> n;

    for(long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end());

    long long start = 0;
    long long end = n - 1;
    long long tmep = INF; //가장 0에 가까운 합

    while(start < end) {
        long long sum = vec[start] + vec[end];

        if (tmep > abs(sum) ) {

            tmep = abs(sum);
            ans[0] = vec[start];
            ans[1] = vec[end];

            if(sum == 0) break;
        }

        if (sum < 0)
            start++;
        else
            end--;
    }

    cout << ans[0] << " " << ans[1];
}