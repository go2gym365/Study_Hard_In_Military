#include<bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if(find(v.begin(), v.end(), num) == v.end()) {
            ans.push_back(0);
        }
        else ans.push_back(1);
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}