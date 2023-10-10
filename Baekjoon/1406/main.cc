#include<bits/stdc++.h>

using namespace std;

int main() {
    deque<char> dq;
    queue<char> temp;

    int n;
    string str;
    cin >> str;
    cin >> n;

    for(int i = 0; i < str.size(); i++) {
        dq.push_back(str[i]);
    }

    int idx = dq.size();

    while(n--) {
        char cmd, input;
        cin >> cmd;

        if(cmd == 'P') {
            cin >> input;
            if(idx == dq.size()) {
                dq.push_back(input);
            }
            else if(idx == 0) {
                dq.push_front(input);
            }
            else {
                if(dq.size() - idx <= dq.size()/2) {
                    for(int i = idx; i < dq.size(); i++) {
                        temp.push(dq.back());
                        dq.pop_back();
                    }
                    dq.push_back(input);
                    for(int i = idx; i < dq.size(); i++) {
                        dq.push_back(temp.front());
                        temp.pop();
                    }
                }
                else {
                    for(int i = 0; i < idx; i++) {
                        temp.push(dq.front());
                        dq.pop_front();
                    }
                    dq.push_front(input);
                    for(int i = 0; i < idx; i++) {
                        dq.push_front(temp.front());
                        temp.pop();
                    }
                }
            }
            idx++;
        }
        else if(cmd == 'B' && idx != 0) {
            //idx 뒤의 숫자가 더 적은 경우
            if(dq.size() - idx <= dq.size()/2) {
                for(int i = idx; i < dq.size(); i++) {
                    temp.push(dq.back());
                    dq.pop_back();
                }
                dq.pop_back();
                for(int i = idx; i < dq.size(); i++) {
                    dq.push_back(temp.front());
                    temp.pop();
                }
                idx--;
            }
            else {
                for(int i = 0; i < idx; i++) {
                    temp.push(dq.front());
                    dq.pop_front();
                }
                dq.pop_front();
                for(int i = 0; i < idx; i++) {
                    dq.push_front(temp.front());
                    temp.pop();
                }
                idx--;
            }
        }
        else if(cmd == 'L' && idx != 0) {
            idx--;
        }
        else if(cmd == 'D' && idx != dq.size()) {
            idx++;
        }
    }
    for(int i = 0; i < dq.size(); i++) {
        cout << dq[i];
    }
}