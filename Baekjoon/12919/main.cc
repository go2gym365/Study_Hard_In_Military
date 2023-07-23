#include<bits/stdc++.h>

using namespace std;

void solve(string str, string goal) {
    if(str == goal) {
        cout << 1 << "\n";
        exit(0);
    }

    if(str.size() >= goal.size()) return;

    if(goal[goal.size() - 1] == 'A') {
        string temp = goal;
        temp.erase(temp.size() - 1);
        solve(str, temp);
    }

    if(goal[0] == 'B') {
        string temp = goal;
        reverse(temp.begin(), temp.end());
        temp.erase(temp.size() - 1);
        solve(str, temp);
    }
}

int main() {
    string str, goal;

    cin >> str >> goal;

    solve(str, goal);

    cout << 0;
}