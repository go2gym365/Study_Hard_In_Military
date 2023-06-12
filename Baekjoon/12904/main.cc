#include<bits/stdc++.h>

using namespace std;

string str, goal;
bool check = 0;

int main() {
    cin >> str;
    cin >> goal;

    while(1) {
        if(str.size() == goal.size()) {
            if(str == goal) {
                check = 1;
            }
        break;
        }
        if(goal[goal.size() - 1] == 'A') {
            goal.pop_back();
        }
        else {
            goal.pop_back();
            reverse(goal.begin(), goal.end());
        }
    }
    cout << check;
}
