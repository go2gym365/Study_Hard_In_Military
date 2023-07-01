#include<bits/stdc++.h>

using namespace std;

vector<int> v;

bool numCheck(int num) {

    string str = to_string(num);
    
    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(str[i] != v[j]) return false;
        }
    }
    return true;
}

int main() {
    int n, m;

    cin >> n >> m;

    if(n == 100) {
        cout << 0;
        return 0;
    }

    if(m == 0) {
        int cnt = 0;

        while(n > 0) {
            n /= 10;
            cnt++;
        }
        cout << cnt;
        return 0;
    }
    else {
        for(int i = 0; i < m; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        
        if(numCheck(n)) {
            int cnt = 0;

            while(n > 0) {
                n /= 10;
                cnt++;
            }
            cout << cnt;
            return 0;
        }
        else {

        }
    }

}