#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        stack<int> s;

        string str;

        cin >> str;

        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(' || s.empty()) s.push(str[i]);
            else if(s.top() == '(') s.pop();
        }

        if(s.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}