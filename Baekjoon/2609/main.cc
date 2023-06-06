#include<bits/stdc++.h>

using namespace std;

//최대공약수 = mod연산을 해서 0이되게 하는 수
int gcd(int a, int b) {
    int c = a % b;
    
    while(c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    cout << gcd(n1, n2) << "\n" << lcm(n1, n2);
}