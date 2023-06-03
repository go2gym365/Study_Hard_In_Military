#include<bits/stdc++.h>

using namespace std;

bool isPrime(int num) {
    if(num == 1) return false;
    else if(num == 2) return true;
    else {
        for(int i = 2; i <= num; i++) {
            for(int j = i * 2; j <= num; j += i) {
                if(j == num) return false;
            }
        }
        return true;
    }    
}

int main() {
    int n, cnt = 0;
    cin >> n;

    while(n--) {
        int num;
        cin >> num;
        if(isPrime(num)) ++cnt;
    }

    cout << cnt << "\n";
}