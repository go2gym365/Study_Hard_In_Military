#include <bits/stdc++.h>

using namespace std;

int main() {
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if(a == 0 && b == 0 && c == 0) break;

        int m = max(max(a, b), c);
        if()
        if(a == b && b == c) 
            cout << "Equilateral\n";
        else if(a == b || b == c || c == b) 
            cout << "Isosceles\n";
        else if(a != b && b != c)
            cout << "Scalene\n";
        
        
    }
}