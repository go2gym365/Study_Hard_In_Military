#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void cantor(int n) {
    int size = pow(3, n-1);
    if(n == 0) {
        cout << "-";
        return;
    }
    
    cantor(n-1);
    
    for(int i = 0; i < size; i++) {
        cout << " ";
    }
    cantor(n-1);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int n;
    while(cin >> n) {
        cantor(n);
        cout << "\n";
    }
}
