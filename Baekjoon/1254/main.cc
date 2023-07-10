#include<bits/stdc++.h>

using namespace std;

int alpha[26];

bool cannotPali() {
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(alpha[i] % 2 == 1)
            cnt++;
    }
    return cnt > 1;
}

int main() {
    string str, ans;
    cin >> str;


    for(int i = 0; i < str.size(); i++) {
        alpha[str[i] - 'a']++;
    }
    
    if(cannotPali()) {
        for(int i = 0; i < 26; i++) {
            if(alpha[i] % 2 == 1)
                alpha[i]++;
        }
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < alpha[i] / 2; j++) {
            ans += alpha[i] + 'a';
        }
    }

    for(int i = 0; i < 26; i++) {
        if(alpha[i] % 2 == 1) {
            ans += alpha[i] + 'a';
        }
    }

    for(int i = 25; i >= 0; i--) {
        for(int j = 0; j < alpha[i] / 2; j++) {
            ans += alpha[i] + 'a';
        }
    }

    cout << ans.length() << " " << ans;
}