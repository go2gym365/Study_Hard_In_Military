#include<bit/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        stack<int> s;

        string str;
        bool check;

        cin >> str;

        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '(') {
                s.push(str[i]);
            }
            else if(str[i] == ')') {
                
            }
        }
    }
}