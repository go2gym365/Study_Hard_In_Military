#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;

    cin >> n;

    while(n--) {
        int num;
        string str; 

        cin >> str;
        if(str == "push") {
            cin >> num;
            v.push_back(num);
        }
        else if(str == "pop") {
            if(v.empty()) cout << "-1" << "\n";
            else {
                cout << v[0] << "\n";
                v.erase(v.begin());
            }
        }
        else if(str == "size") {
            cout << v.size() << "\n";
        }
        else if(str == "empty") {
            if(v.size() == 0) cout << '1' << "\n";
            else cout << '0' << "\n";
        }
        else if(str == "front") {
            if(v.size() == 0) cout << "-1" << "\n";
            else cout << v[0] << "\n";
        }
        else if(str == "back") {
            if(v.size() == 0) cout << "-1" << "\n";
            else cout << v[v.size() - 1] << "\n";
        }
    }
}