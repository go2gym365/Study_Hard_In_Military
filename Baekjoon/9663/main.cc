#include<bits/stdc++.h>

using namespace std;

vector<int> vec(16, 0);

int n;
int ans = 0;

void queen(int x) {
    if(n == x) ans++;
    else {
        for(int i = 0; i < n; i++) {
            vec[x] = i; //퀸의 위치를 정함
            bool check = true;
            for(int j = 0; j < x; j++) {
                if(vec[x] == vec[j] || abs(vec[x] - vec[j] == x - j)) {
                    check = false;
                    break;
                }
            }
            if(check) {
                queen(x + 1);
            }
        }
    }
}

int main() {
    cin >> n;

    queen();
    cout << ans;
}

//https://hagisilecoding.tistory.com/46