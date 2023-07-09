#include<bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2;
    int count = 0;
    int res = 987654321;

    cin >> str1 >> str2;

    for(int i = 0; i <= str2.size() - str1.size(); i++) {
        count = 0;
        for(int j = 0; j < str1.length(); j++) {
            if(str1[j] != str2[j + i])
                count++;
        }
        res = min(res, count);
    }

    cout << res;
}