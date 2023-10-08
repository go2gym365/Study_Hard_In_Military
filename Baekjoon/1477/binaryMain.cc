#include<bits/stdc++.h>

using namespace std;

int n, m, l;
vector<int> input;
vector<int> sum;

bool check(int mid) {
    int cnt = 0;
    for(int i = 0; i < n + 1; i++) {
        if(sum[i] % mid == 0) {
            cnt += (sum[i] / mid) - 1;
        }
        else {
            cnt += sum[i] / mid;
        }
    }

    if(cnt <= m) return true;
    else return false;
}

void binarySearch() {
    int start = 0;
    int end = l;

    while(start+1 < end) {
        int mid = (start + end) / 2;

        if(check(mid)) end = mid;
        else start = mid;
    }

    cout << end;
}

int main() {
    cin >> n >> m >> l;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }

    sort(input.begin(), input.end());

    int prev = 0;
    for(int i = 0; i < n; i++) {
        sum.push_back(input[i]-prev);
        prev = input[i];
    }
    sum.push_back(l - prev);


    binarySearch();
}