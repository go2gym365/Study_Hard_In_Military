#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    int cnt = 0;

    for(int i = 2; i <= n; cnt++) {
        i += cnt * 6;
    }

    if(n == 1) cnt=1;
    cout << cnt;
}