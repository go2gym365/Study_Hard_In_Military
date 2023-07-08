#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int cnt = 0;
    
    cin >> n; 

    for(int i = 0; i < n; i++) {
        bool isGroup = true;
        string str;
        cin >> str;
        str.erase(unique(str.begin(), str.end()), str.end());
        sort(str.begin(), str.end());

        for(int j = 0; j < str.size(); j++) {
            if(str[j] == str[j + 1]){
                isGroup = false;
                break;
            }
        }
        if(isGroup)
            cnt++;
    }
    cout << cnt;
}

https://hagisilecoding.tistory.com/53