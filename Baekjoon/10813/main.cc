#include<bits/stdc++.h>

using namespace std;

vector<int> v(101, 0);

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        v[i] = i;
    }

    while(m--) {
        int n1, n2;
        cin >> n1 >> n2;
        int temp = v[n1];
        v[n1] = v[n2];
        v[n2] = temp;
    }

    for(int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
}