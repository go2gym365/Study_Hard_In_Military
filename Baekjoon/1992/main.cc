#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

string input[65];

void solve(int y, int x, int size) {
    bool check = false;
    for(int i = y; i < y+size; i++) {
        for(int j = x; j < x+size; j++) {
            if(input[y][x] != input[i][j]) {
                check = true;
                break;
            }
        }
        if(check) break;
    }
    
    if(check) {
        cout << '(';
        solve(y, x, size / 2);
        solve(y, x + size/2, size / 2);
        solve(y + size/2, x, size / 2);
        solve(y + size/2, x + size/2, size / 2);
        cout << ')';
    }
    else {
        cout << input[y][x];
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    solve(0, 0, n);
}
