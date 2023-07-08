#include<bits/stdc++.h>

using namespace std;

vector<string> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;

    cin >> str;

    for(int i = 1; i <= str.size(); i++) {
        string temp = "";
        for(int j = str.size() - i; j < str.size(); j++) {
            temp += str[j];
        }
        ans.push_back(temp);
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
}