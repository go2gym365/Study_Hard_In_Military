#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    int temp = 0;

    for(int i = 0; i < n; i++) {
        int solveCnt;
        cin >> solveCnt;

        if(n == 1 && solveCnt == 0) {
            cout << 0;
            return 0;
        }

        if(solveCnt == 0 && temp > 0) {
            ans = max(ans, temp);
            temp = 0;
        }

        if(solveCnt > 0) {
            temp++;
        }
    }
    ans = max(ans, temp);

    cout << ans;
}