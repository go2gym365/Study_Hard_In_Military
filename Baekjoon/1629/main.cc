#include<bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b, long long c) {
    if(b == 1) return a % c;
    long long val = solve(a, b / 2, c);
    val = val * val % c;
    if(b % 2 == 0) return val;
    return val * a % c;
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    cout << solve(a, b, c);
}