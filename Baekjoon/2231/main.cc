#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int result = 0;
    cin >> n;

    for(int  i = 1; i < n; i++) {
        int sum = 0;
        int num = i;
        while(num != 0) {
            sum += num % 10;
            num /= 10;
        }
        if(sum + i == n) {
            result = i;
            break;
        }
    }
    cout << result;
}