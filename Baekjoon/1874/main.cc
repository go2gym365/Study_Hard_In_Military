#include<bits/stdc++.h>

using namespace std;

stack<int> s;
vector<char> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    bool check = true;
    cin >> n;

    int lastIn = 1;

    while(n--) {
        int num;
        cin >> num;

        for(int i = lastIn; i <= num; i++) {
            s.push(i);
            lastIn += 1;
            v.push_back('+');
        }

        if(s.top() == num) {
            s.pop();
            v.push_back('-');
        }
        else {
            check = false;
            cout << "NO" << "\n";
            break;
        }
    }
    if(check) {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i] << "\n";
        }
    }
}