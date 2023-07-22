#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        multiset<int> ms;

        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            char c;
            int num;

            cin >> c >> num;

            if(c == 'I') {
                ms.insert(num);
            }
            else if(c == 'D') {
                if(ms.empty()) continue;
                if(num == 1) {
                    ms.erase(--ms.end());
                }
                else if(num == -1) {
                    ms.erase(ms.begin());
                }
            }

        }
        if(ms.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << *(--ms.end()) << ' ' << *ms.begin() << "\n";
        }
    }
}