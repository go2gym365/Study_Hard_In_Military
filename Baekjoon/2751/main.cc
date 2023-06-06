#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    int num;

    cin >> num;

    for(int i = 0; i < num; i++) {
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(),v.end());

    for(int i = 0; i < num; i++)
        cout << v[i] << '\n';
}