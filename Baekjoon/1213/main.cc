#include<bits/stdc++.h>

using namespace std;

int alpha[26];

bool cannotPalin() {
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(alpha[i] % 2 == 1)
            cnt++
    }
    return cnt > 1;
}

int main() {
    string str, ans;
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        alpha[str[i] - 'A']++;
    }

    if(cannotPalin()) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < alpha[i] / 2; j++) {
            ans += i + 'A';
        }
    }
}