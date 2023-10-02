#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> input;

bool cmp(string a, string b) {
    if(a == b) return a < b;

    string ab = a + b;
    string ba = b + a;

    if (ab > ba)
        return true;
    else
        return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    bool check = false;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;

        input.push_back(a);
        if (a != "0")
            check = true;
    }

    if (!check)
        cout << 0;
    else {
        sort(input.begin(), input.end(), cmp);

        for (int i = 0; i < n; i++) {
            cout << input[i];
        }
    }
}