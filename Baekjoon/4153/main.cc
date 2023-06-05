#include<bits/stdc++.h>

using namespace std;

int main() {
    while(1) {
        int a, b, c;
        int temp = 0;
        cin >> a >> b >> c;
        
        if(a == 0 && b == 0 && c == 0) break;
        if(a > b) {
            temp = b;
            b = a;
            a = temp;
        }
        if(b > c) {
            temp = c;
            c = b;
            b = temp;
        }
        if(c * c == a * a + b * b) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
}