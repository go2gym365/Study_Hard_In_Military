#include<bits/stdc++.h>

using namespace std;

int main() {
    deque<char>left;
    deque<char>right;

    string str;
    int n;
    
    cin >> str >> n;

    for(int i = 0; i < str.size(); i++) {
        left.push_back(str[i]);
    }


    for(int i = 0; i < n; i++) {
        char cmd;
        cin >> cmd;
        if(cmd == 'L' && !left.empty()) {
            right.push_front(left.back());
            left.pop_back();
        }
        else if(cmd == 'D' && !right.empty()) {
            left.push_back(right.front());
            right.pop_front();
        }
        else if(cmd == 'B' && !left.empty()) {
            left.pop_back();
        }
        else if(cmd == 'P') {
            char c;
            cin >> c;
            left.push_back(c);
        }
    }

    while(!left.empty()) {
        cout << left.front();
        left.pop_front();
    }

    while(!right.empty()) {
        cout << right.front();
        right.pop_front();
    }
}