#include<bits/stdc++.h>

using namespace std;

int first(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int sec(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i*i;
    }
    return sum;
}

int thi(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i * i * i;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    int fir = first(n);

    cout << first(n) << "\n" << fir * fir << "\n" << thi(n);
}