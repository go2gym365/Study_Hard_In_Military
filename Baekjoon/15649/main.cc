#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[10] = {0, };
bool vis[10] = {false, };

void func(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]) {
            vis[i] = true;
            arr[cnt] = i;
            func(cnt + 1);
            vis[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    func(0);
}