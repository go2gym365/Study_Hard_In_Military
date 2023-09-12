#include<bits/stdc++.h>

using namespace std;

int alpha[26];

bool cmp(int &a, int &b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int pow = 1;
        for(int j = str.size() - 1; j >= 0; j--) {
            alpha[str[j] - 'A'] += pow;
            pow *= 10;
        }
    }

    sort(alpha, alpha + 26, cmp);

    int num = 9;
    int answer = 0;

    for(int i = 0; i < 26; i++) {
        if(alpha[i] == 0) break;
        answer += alpha[i] * num--;
    }
    cout << answer;
}