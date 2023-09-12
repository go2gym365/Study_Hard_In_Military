#include<bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<>> card;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    int ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        card.push(a);
    }

    while(card.size() != 1) {
        int c1 = card.top();
        card.pop();
        int c2 = card.top();
        card.pop();

        ans += c1 + c2;
        card.push(c1 + c2);
    }

    cout << ans;
}