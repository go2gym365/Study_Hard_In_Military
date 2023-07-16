#include<bits/stdc++.h>

using namespace std;

vector<int> vec;
vector<int> cmp;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
        cmp.push_back(a);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    for(int i = 0; i < n; i++) {
        cout << lower_bound(vec.begin(), vec.end(), cmp[i]) - vec.begin() << " ";
    }
}