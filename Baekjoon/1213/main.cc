#include<bits/stdc++.h>

using namespace std;

int alpha[26];


//알파벳의 갯수가 홀수인 알파벳이 2개 이상이면 펠린드롬 못만듬
bool cannotPalin() {
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

    for(int i = 0; i < 26; i++) {
        if(alpha[i] % 2) {
            ans += i + 'A';
        }
    }
    for(int i = 25; i >= 0; i--) {
        for(int j = 0; j < alpha[i] / 2; j++) {
            ans += i + 'A';
        }
    }

    cout << ans;
}