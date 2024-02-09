#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for(int cur = 0; cur < n; cur++) {
        for(int i = 0; i < cur; i++) {
            cout << ' ';
        }
        
        for(int i = 0; i < 2*(n-cur)-1; i++) {
            cout << '*';
        }
        
        cout << '\n';
    }
}