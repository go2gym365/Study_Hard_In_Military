#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, m;
    
    cin >> n >> m;
    
    if(n == m) {
        cout << 2*(n-1);
    }
    else if(n > m) {
        cout << 2*(m-1) + 1;
    }
    else {
        cout << 2*(n-1);
    }
}