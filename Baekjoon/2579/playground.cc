#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 3;
    int b = 4;
    int &c = a;
    c = 5;
    cout << a;    
}