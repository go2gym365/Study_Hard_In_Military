#include<bits/stdc++.h>

using namespace std;

vector<long long> input;
vector<long long> ans(3, 0);
long long res = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; 
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    sort(input.begin(), input.end());

    for(int i = 0; i < n - 2; i++) {
        int left = i+1;
        int right = n - 1;

        while(left < right) {
            long long val = input[i] + input[left] + input[right];

            if(abs(val) < res) {
                ans[0] = input[i];
                ans[1] = input[left];
                ans[2] = input[right];
                res = abs(val);
            }

            if(val < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    for(int i = 0; i < 3; i++) {
        cout << ans[i] << " ";
    }
}