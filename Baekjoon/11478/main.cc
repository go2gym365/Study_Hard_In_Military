#include<bits/stdc++.h>

using namespace std;

set<string> s;

int main() {
    string str;
    string temp = "";
    
    cin >> str;    
    
    for(int i = 0; i < str.size(); i++) {
        for(int j = i; j < str.size(); j++) {
            temp += str[j];
            s.insert(temp);
        }
        temp = "";
    }
    cout << s.size();
}