#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        deque<int> dq;
        string order, str;
        string temp = "";
        int n;

        cin >> order;
        cin >> n;
        cin >> str;

        for(int j = 0; j < str.size(); j++) {
            if(isdigit(str[j])) {
                temp += str[j];
            }
            else {
                if(!temp.empty()) {
                    dq.push_back(stoi(temp));
                    temp = "";
                }
            }
        }

        bool check = false;
        bool error = false;

        for(int j = 0; j < order.size(); j++) {
            if(order[j] == 'R') {
                check = !check;
            }
            else if(order[j] == 'D') {
                if(dq.empty()) {
                    error = true;
                    continue;
                }
                else {
                    if(check) {
                        dq.pop_back();
                    }
                    else {
                        dq.pop_front();
                    }
                }
            }
        }

        if(error) {
            cout << "error" << "\n";
        }
        else {
            cout << '[';
            while(!dq.empty()) {
                if(check) {
                    cout << dq.back();
                    if(dq.size() > 1) {
                        cout << ',';
                    }
                    dq.pop_back();
                }
                else {
                    cout << dq.front();
                    if(dq.size() > 1) {
                        cout << ',';
                    }
                    dq.pop_front();
                }
            }
            cout << "]\n";
        }
    }
}