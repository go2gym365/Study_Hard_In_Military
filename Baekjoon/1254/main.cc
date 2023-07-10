#include<bits/stdc++.h>

using namespace std;

bool isPali(string str) {
    string temp = str;
    reverse(temp.begin(), temp.end());

    if(temp == str) return true;
    else return false;
}

int main() {
    string str, ans;
    cin >> str;

    if(isPali(str)) {
        cout << str.size();
        return 0;
    }

    for(int i = 0; i < str.size(); i++) {
        string temp = str;
        for(int j = i; j >= 0; j--) {
            temp += str[j];
            if(isPali(temp)) {
                cout << temp.length();
                return 0;
            }
            else continue;
        }
    }
}