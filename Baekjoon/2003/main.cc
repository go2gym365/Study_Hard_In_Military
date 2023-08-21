#include<bits/stdc++.h>

using namespace std;

vector<int> vec;

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }

    int cnt = 0;
    int end = 0;
    int start = 0;
    int sum = vec[0];

    while(end < n) {
        if(sum < m) {
            end++;
            sum += vec[end];
        }
        else if(sum == m) {
            end++;
            sum += vec[end];
            sum -= vec[start];
            start++;
        }
        else if(sum  > m) {
            sum -= vec[start];
            start++;
        }
    }
    cout << cnt;
}