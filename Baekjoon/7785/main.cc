#include <bits/stdc++.h>

using namespace std;

map<string, bool, greater<string>> m;

int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string name, cmd;
        cin >> name >> cmd;
        
        if(cmd == "enter"){
            m[name] = true;
        }
        else if(cmd == "leave")
            m[name] = false;
    }
    
    for(auto i = m.begin(); i != m.end(); i++) {
        if(i->second == true) {
            cout << i->first << "\n";
        }
    }
}
