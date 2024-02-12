#include<bits/stdc++.h>

using namespace std;

string cloaStr[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
    string str;
    cin >> str;
    
    for(int i = 0; i < 8; i++) {
        while(1) {
            int idx = str.find(cloaStr[i]);
            if(idx == string::npos) break;
            str.replace(idx, cloaStr[i].length(), "a");
        }
    }
    
    cout << str.size();
}