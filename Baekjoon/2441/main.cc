#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            cout << ' ';
        }
        
        for(int k = 0; k < n - i; k++) {
            cout << '*';
        }
        cout << '\n';
    }
}
