#include<bits/stdc++.h>

using namespace std;

int main() {
    while(1) {
        stack<char> s;

        bool ckech = false;
        string str;

        getline(cin, str);

        if(str == '.') break;

        for(int i = 0; i < str.size(); i++) {
            char c = str[i];

            if(c == '[' || c == '(') s.push(c);
            else if(c == ')') {
                if(!s.empty() && s.top() =='(') s.pop();
                else {
                    check = true;
                    break;
                }
            }
            else if(c == ']') {
                if(!s.empty() && s.top() == '[') s.pop();
                else {
                    check = true;
                    break;
                }
            }
        }
        if(!flag && s.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}