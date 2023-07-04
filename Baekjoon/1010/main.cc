#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
 
        long long ans = 1;

        int r = 1;
        for(int i = 0; i > m - n; i--) {
            ans *= i;
            ans /= r++;
        }
        cout << ans << '\n';
    }
}