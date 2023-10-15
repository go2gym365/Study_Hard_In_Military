#include<bits/stdc++.h>

using namespace std;

vector<string> vec;
vector<string> can;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    map<string, int> mmap;
    int n, m;
    int qidx;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        
        if(n == 1) {
            cout << str;
            break;
        }
        
        if(str == "?") qidx = i;

        vec.push_back(str);
        mmap[str]++;
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        string str;
        cin >> str;

        can.push_back(str);
    }

    string fir = vec[qidx - 1];
    string sec = vec[qidx + 1];
    
    
    
    for(int i = 0; i < m; i++) {
        if(!mmap[can[i]]) {
            if(can[i].front() == fir.back()) {
                if(can[i].back() == sec.front()) {
                    cout << can[i];
                    break;
                }
            }
        }
    }
    return 0;
}