#include<bits/stdc++.h>

using namespace std;

vector<int> v;

int n, m;
int ans = 987654321;
int value;

bool numCheck(int num) {
    string str = to_string(num);
    
    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(str[i] != v[j]) return false;
        }
    }
    return true;
}

void selNum(int culNum, int cnt) {
    if(culNum > 1000001) return;
    if(culNum == m) {
        if (ans > cnt) {
            ans = cnt;
            value = culNum;
        }
        return;
    }
    else {
        int temp = cnt + abs(m - culNum);
        if(ans > temp) {
            ans = temp;
            value = culNum;
        }
    }

    for(int i  = 0; i < 10; i++) {
        if(culNum == 0 && i == 0) continue; 
        if(find(v.begin(), v.end(), i) != v.end()) continue;
        selNum(culNum * 10 + i, cnt + 1);
    }
}

int main() {
    cin >> n >> m;

    if(m != 0) {
        for(int i = 0; i < m; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
    }

    if(m == 0 || numCheck(n)) {
        int cnt = 0;
        int temp = n;
        while(temp > 0) {
            temp /= 10;
            cnt++;
        }
        if(ans > cnt) {
            ans = cnt;
            value = n; 
        }
    }

    if(!numCheck(n)) {
        selNum(0, 0);
    }

    ans = min(ans, abs(m - 100));

    cout << ans << " " << value;
}