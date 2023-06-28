#include<bits/stdc++.h>

using namespace std;
 
vector<char> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        v.push_back(str[i]);
    }

    str = "";

    sort(v.begin(), v.end(), greater<>());

    for(int i = 0; i < v.size(); i++) {
        str += v[i];
    }

    cout << str;
}