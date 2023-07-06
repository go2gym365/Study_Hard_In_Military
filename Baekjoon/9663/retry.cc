#include<bits/stdc++.h>

using namespace std;

vector<int> vec(16, 0);

int n;
int cnt = 0;

void queen(int x) {
    if(n == x) {
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++) {
        vec[x] = i;
        bool check = true;
        for(int j = 0; j < x; j++) {
            if(vec[x] == vec[j] || abs(vec[x] - vec[j]) == x - j) {
                check = false;
                break;
            }
        }
        if(check) queen(x + 1);
    }
}

int main() {
    cin >> n;

    queen(0);

    cout << cnt;
}