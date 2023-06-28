#include<bits/stdc++.h>

using namespace std;

void solve(int a, int b, int n) {
    if(n == 1) {
        cout << a << ' ' << b << "\n";
        return;
    }

    solve(a, 6 - a - b, n - 1);
    cout << a << " " << b << "\n";
    solve(6 - a - b, b, n - 1);
}

int main() {
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";

    solve(1, 3, n);
}