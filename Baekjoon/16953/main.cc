#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    int cnt = 0;

    cin >> a >> b;

    while(1) {
        if(a == b) break;
        if(a > b) {
            cout << -1;
            return 0;
        }

        if(b % 2 == 0) {
            b /= 2;
            cnt++;
        }

        else if(b % 10 == 1) {
            b /= 10;
            cnt++;
        }
        else {
            cout << -1;
            return 0;
        }
    }

    cout << cnt + 1;
}