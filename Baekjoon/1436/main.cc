#include<bits/stdc++.h>

using namespace std;

int n, ans, cnt, temp;

int main() {
    cin >> n;
    cnt = 0;
    ans = 0;
    while(cnt != n) {
        ans++;
        temp = ans;
        
        while(temp != 0) {
            if(temp % 1000 == 666) {
                cnt++;
                break;
            }
            else temp /= 10;
        }
    }

    cout << ans;
}