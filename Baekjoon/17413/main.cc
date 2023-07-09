#include<bits/stdc++.h>

using namespace std;

stack<char> sta;

int main() {
    string str;
    getline(cin, str);

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '<') {
            while(!sta.empty()) {
                cout << sta.top();
                sta.pop();
            }
            while(1) {
                cout << str[i];
                if(str[i] == '>') 
                    break;
                i++;
            }
        }
        else if(str[i] == ' ') {
            while(!sta.empty()) {
                cout << sta.top();
                sta.pop();
            }
            cout << " ";
        }
        else 
            sta.push(str[i]);
    }
    while(!sta.empty()) {
        cout << sta.top();
        sta.pop();
    }
}