#include<bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2;
    int count = 0;
    int result = 0x3f3f3f3f;
    
    cin >> str1 >> str2;

    for(int i = 0; i <= str2.size() - str1.size(); i++) {
        count = 0;

        for(int j = 0; j < str1.length(); j++) {
            if (str1[j] != str2[j + i]) 
                count++;
        }
        result = min(result, count);
    }
    cout << result;
}