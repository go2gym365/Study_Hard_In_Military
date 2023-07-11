#include<bits/stdc++.h>

using namespace std;

int main() {
    string str, ex;
    bool check = true;

    cin >> str, ex;

    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j < ex.size(); j++) {
            if(str[j] != ex[i]) {
                check = false;
            }
            else {
                i++;
            }
        }
    }
}