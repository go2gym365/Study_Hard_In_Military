#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if(a >= 300) 
            cout << 1 << " ";
        else if(a < 300 && a >= 275) 
            cout << 2 << " ";
        else if(a < 275 && a >= 250)
            cout << 3 << " ";
        else if(a < 250)
            cout << 4 << " ";
    }
}