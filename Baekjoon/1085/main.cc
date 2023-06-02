#include<bits/stdc++.h>

using namespace std;

int main() {
    int x, y, w, h;
    int res = 0;
    cin >> x >> y >> w >> h;

    res = (h - y) > (w - x) ?  w - x :  h - y;
    if(x - 0 < res) res = x;
    if(y - 0 < res) res = y;

    cout << res;
}