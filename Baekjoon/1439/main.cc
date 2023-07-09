#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    string str;
    int ans = 0;

    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] != str[i + 1]) 
            ans++;
    }

    cout << ans / 2;
}