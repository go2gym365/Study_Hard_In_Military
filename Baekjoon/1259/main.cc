#include<bits/stdc++.h>

using namespace std;

int main() {
    while(1) {
        string str, temp;

        cin >> str;
        if(str == "0") break;
        temp = str;
        reverse(temp.begin(), temp.end());

        if(temp == str) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}