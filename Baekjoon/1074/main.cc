#include<bits/stdc++.h>

using namespace std;

int N, r, c;
int cnt = 0;
int ans = -1;

void Zcount(int x, int y, int node) {
    if(ans != -1) return;
    if(x == c && y == r){
        ans = cnt;
        return;
    }
    if(node == 0) {
        cnt++;
        return;
    }

    if(x <= c && c < x + node && y <= r && r < y + node) {
        Zcount(x, y, node / 2);
    }
    else if(x + node <= c && c < x + 2 * node && y <= r && r < y + node) {
        cnt += node * node;
        Zcount(x + node, y, node / 2);
    }
    else if(x <= c && c < x + node && y + node <= r && r < y + 2 * node){
        cnt += 2 * node * node;
        Zcount(x, y + node, node / 2);
    }
    else if(x + node <= c && c < x + 2 * node && y + node <= r && r < y + 2 * node) {
        cnt += 3 * node * node;
        Zcount(x + node, y + node, node / 2);
    }

}

int main() {

    cin >> N >> r >> c;

    long long start = pow(2, N) / 2;

    Zcount(0, 0, start);

    cout << ans;
}