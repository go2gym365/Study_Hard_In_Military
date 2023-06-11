#include<bits/stdc++.h>

using namespace std;

vector<int> v(10001, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        v[a]++;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < v[i]; j++) {
            cout << i;
        }
    }
}