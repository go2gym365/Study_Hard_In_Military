#include<bits/stdc++.h>
using namespace std;

int arr[10] = {};

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int num = a * b * c;

    while(num != 0) {
        arr[num % 10]++;
        num /= 10;
    }

    for(int n : arr) {
        cout << n << "\n";
    }
}