#include<bits/stdc++.h>

using namespace std;

vector<string>v;

bool compare(string a, string b) {
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);

    for(string s : v) { 
        cout << s << "\n";
    }
}