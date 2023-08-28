#include<bits/stdc++.h>

using namespace std;

vector<int> vec;
deque<int> dq;

int main() {
    int n, m;
    int cnt = 0;

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for(int i = 0; i < m; i++) {
        int a;
        int left, right;
        
        cin >> a;
        
        for (int i = 0; i < dq.size(); i++) {
            if(dq[i] == a) {
                left = i;
                right = dq.size() - i;
                break;
            }
        }

        if (left <= right) {
            while(true) {
                if(dq.front() == a) {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        } 
        else {
            while(true) {
                if(dq.front()== a) {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
    }
    cout << cnt;
}