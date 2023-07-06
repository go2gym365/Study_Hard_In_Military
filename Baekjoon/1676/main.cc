#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int cnt = 0;

    cin >> n;

    while(n--) {
        int num = n;
        while(num >= 0) {
            if(num % 10 == 0) {
                cnt++;
            }
            if(num < 0) break;
            num /= 10;
        }
    }
    cout << cnt;
}