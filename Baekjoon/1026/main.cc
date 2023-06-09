#include<bits/stdc++.h>

using namespace std;

vector<int> n1;
vector<int> n2;

int main() {
    int n;
    int ans = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        n1.push_back(a);
    }

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        n2.push_back(a);
    }

    sort(n1.begin(), n1.end(), greater<>());
    sort(n2.begin(), n2.end());
    
    for(int i = 0; i < n; i++) {
        ans += n2[i] * n1[i];
    }

    cout << ans;
}