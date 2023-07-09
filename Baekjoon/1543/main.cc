#include<bits/stdc++.h>

using namespace std;

int main() {
    string ex, str;
    int cnt = 0;

    getline(cin, ex);
    getline(cin, str);

    for(int i = 0; i < ex.size(); i++) {
        bool check = true;
        for(int j = 0; j < str.size(); j++) {
            if(ex[i + j] != str[j]) {
                check = false;
                break;
            }
        }
        if(check) {
            cnt++;
            i += str.size() - 1;
        }
    }
    cout << cnt;
}