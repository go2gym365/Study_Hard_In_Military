#include<bits/stdc++.h>

using namespace std;

int priority(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    stack<char> oper;
    
    string ans = "";
    string str;
    
    cin >> str;
    
    for(int i = 0; i < str.size(); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            cout << str[i];
            continue;
        }
        
        if(oper.empty() || str[i] == '(') {
            oper.push(str[i]);
            continue;
        }
        
        if(str[i] == ')') {
            while(oper.top() != '(') {
                cout << oper.top();
                oper.pop();
            }
            oper.pop();
            continue;
        }
        
        if(priority(oper.top()) < priority(str[i])) {
            oper.push(str[i]);
        }
        else {
            while(!oper.empty() && priority(oper.top()) >= priority(str[i])) {
                cout << oper.top();
                oper.pop();
            }
            oper.push(str[i]);
        }
    }
    
    while(!oper.empty()) {
        cout << oper.top();
        oper.pop();
    }
}