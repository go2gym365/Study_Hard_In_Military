#include<bits/stdc++.h>

using namespace std;

vector<int> vec;

int main() {
    int n;
    int ans = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if(vec[i] <= a) ans++;
    }

    cout << ans;
}