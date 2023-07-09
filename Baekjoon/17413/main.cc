#include<bits/stdc++.h>

using namespace std;

stack<char> sta;

int main() {
    string str;
    getline(cin, str);

    for(int i = 0; i <= str.size(); i++) {
        if(str[i] == '<') {
            if(!sta.empty()) {
                while(!sta.empty()) {
                cout << sta.top();
                sta.pop();
                }
            }
            while(1) {
                cout << str[i];
                i += 1;
                if(str[i] == '>') break;
            }
        }

        sta.push(str[i]);

        if(str[i] == ' ') {
            while(!sta.empty()) {
                cout << sta.top();
                sta.pop();
            }
        }
    }
    while(!sta.empty()) {
        cout << sta.top();
        sta.pop();
    }
}