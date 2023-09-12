#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin >> str;
    
    //내림차순으로 정리하여 마지막에서 0을 판별
    sort(str.begin(), str.end(), greater<>());

    if(str[str.size() - 1] != '0') {
        cout << -1;
    }
    else {
        long long num = stoll(str);
        if(num % 3 == 0) cout << str;
        else cout << -1;
    }
}