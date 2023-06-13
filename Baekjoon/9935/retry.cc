#include<bits/stdc++.h>

using namespace std;

int main() {
    string str, boom;
    string temp = "";

    cin >> str;
    cin >> boom;

    for(int i = 0; i < str.size(); i++) {
        temp += str[i];
        if(temp.back() == boom.back()) {
            bool check = true;
            for(int j = 0; j < boom.size(); j++) {
                if(temp[temp.size() - boom.size() + j] != boom[j]) {
                    check = false;
                    continue;
                }
            }
            if(check) {
                for(int j = 0; j < boom.size(); j++) {
                    temp.pop_back();
                }
            }
        }
    }
    if(temp.empty()) cout << "FRULA";
    else cout << temp;
}