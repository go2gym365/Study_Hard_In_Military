#include<bits/stdc++.h>

using namespace std;

struct Cmp {
    bool operator() (const string &a, const string &b) const {
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }
};

set<string, Cmp> s;

int main() {
    int n;

    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        s.insert(str);
    }

    for (auto m : s) {
        cout << m << "\n";
    }
}