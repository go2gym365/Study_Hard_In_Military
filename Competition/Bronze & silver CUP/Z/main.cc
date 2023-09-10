#include<bits/stdc++.h>

using namespace std;

map<string, bool> m;

int main() {
    m["Never gonna give you up"] = true;
    m["Never gonna let you down"] = true;
    m["Never gonna run around and desert you"] = true;
    m["Never gonna make you cry"] = true;
    m["Never gonna say goodbye"] = true;
    m["Never gonna tell a lie and hurt you"] = true;
    m["Never gonna stop"] = true;

    int n;
    cin >> n;

    while(n--) {
        string str;
        cin >> str;

        if(!m[str]) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}