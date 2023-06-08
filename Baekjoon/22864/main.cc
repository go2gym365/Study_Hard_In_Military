#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, m;
    int cnt = 0;
    int ans = 0;
    int exhaust = 0;

    cin >> a >> b >> c >> m;

    while(1) {
        exhaust += a;
        if(exhaust > m) {
            exhaust -= a;
            exhaust -= c;
            if(exhaust < 0) exhaust = 0;
        }
        else {
            ans += b;
        }
        cnt++;
        if(cnt == 24) break;
    }

    cout << ans;
}