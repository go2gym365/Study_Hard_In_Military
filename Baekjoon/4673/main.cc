#include<bits/stdc++.h>

using namespace std;

bool check[10001];

int cur(int num) {
    int sum = num;
    
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    for(int i = 1; i < 10001; i++) {
        int n = cur(i);
        if(n < 10001) {
            check[n] = true;
        }
    }
    
    for(int i = 1; i< 10001; i++) {
        if(!check[i]) {
            cout << i << "\n";
        }
    }
}
