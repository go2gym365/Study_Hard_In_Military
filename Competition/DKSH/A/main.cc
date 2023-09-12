#include<bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 0;
    string str;
    string dksh = "DKSH";

    cin >> str;

    for(int i = 0; i < str.size() - 3; i++) {
        bool check = false;
        for(int j = 0; j < 4; j++) {
            if(str[i + j] != dksh[j]) {
                check = true;
                break;
            }
        }
        if(!check) cnt++;
    }

    cout << cnt;
}