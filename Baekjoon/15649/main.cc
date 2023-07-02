#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool vis[10];

void func(int cnt) {
    if(cnt = m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i  = 0; i < n; i++){
        if(!vis[i]) {
            arr[cnt] = i;
            vis[i] = 1;
            func(cnt + 1);
            vis[1] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    func(0);
}