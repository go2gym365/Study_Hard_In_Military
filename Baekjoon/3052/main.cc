#include<bits/stdc++.h>
using namespace std;

int Count[42] = {};

int main() {
    for(int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        Count[n % 42]++;
    }

    int result = 0;
    for(int m : Count) {
        if(m > 0) result++;
    }

    cout << result;
}