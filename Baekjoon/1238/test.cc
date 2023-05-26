#include <bits/stdc++.h>

using namespace std;
int d[4];
vector<int> arr(4);

int main() {
    d[1] = 1;
    arr[1] = 1;
    cout << *(arr.begin() + 1);

    sort(arr.begin(), arr.end());
    sort(d, d + 4);
}