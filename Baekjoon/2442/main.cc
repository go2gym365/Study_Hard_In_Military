#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++) {
            cout << ' ';
        }
        
        for(int k = 0; k < 2*i+1; k++) {
            cout << '*';
        }
        cout << '\n';
    }
}