#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    cin >> str;

    int ans = 0;
    string num = "";
    bool operCheck = false;

    for (int i = 0; i <= str.size(); i++) {        
        if (str[i] == '-' || str[i] == '+' || i==str.size()) {
            if (operCheck) {
                ans -= stoi(num);
                num = "";
            }
            else {
                ans += stoi(num);
                num = "";
            }
        }
        else {
            num += str[i];
        }

        if (str[i] == '-') {
            operCheck = true;
        }    
    }

    cout << ans;
}