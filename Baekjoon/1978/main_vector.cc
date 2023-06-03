#include<bits/stdc++.h>

using namespace std;

vector<bool>isPrime(1001, true);

void checkPrime() {
    isPrime[1] = false;

    for(int i = 2; i <= 1001; i++) {
        for(int j = i * i; j <= 1001; j += i) {
            isPrime[j] = false;
        }
    }
    isPrime[2] = true;
}

int main() {
    int n, cnt = 0;
    cin >> n;

    checkPrime();

    while(n--) {
        int num;
        cin >> num;

        if(isPrime[num]) cnt++;
    }

    cout << cnt << "\n";
}