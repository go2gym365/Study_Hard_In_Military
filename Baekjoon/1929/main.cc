#include<bits/stdc++.h>

using namespace std;

vector<bool>isPrime(1000001, true);

int main() {
    
    int m, n;
    cin >> m >> n;

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i <= sqrt(n); i++) {
        for(int j = i * 2; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    for(int i = m; i <= n; i++) {
        if(isPrime[i])
            cout << i << "\n";
    }
}