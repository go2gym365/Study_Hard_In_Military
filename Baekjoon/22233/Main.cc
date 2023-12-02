#include <bits/stdc++.h>

using namespace std;

unordered_set<string> us;
unordered_set<string>::iterator it;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    
    int n, m;
    int ans;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        us.insert(str);
    }
    
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;
        
        string temp = "";
        
        for(int j = 0; j < str.length(); j++) {
            temp += str[j];
            if(str[j+1] == ',') {
                if(us.find(temp) != us.end()) {
                    it = us.find(temp);
                    us.erase(it);
                }
                temp = "";
                j++;
            }
        }
        if(us.find(temp) != us.end()) {
            it = us.find(temp);
            us.erase(it);
        }
        cout << us.size() << "\n";
    }
}
