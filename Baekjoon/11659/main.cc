#include<bits/stdc++.h>

using namespace std;

vector<int> num;

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        num.push_back(a);
    }

    for(int i = 0; i < m; i++) {
        int start, end;
        int sum = 0;
        cin >> start >> end;

        for(int j = start - 1; j < end; j++) {
            sum += j;
        }
        cout << sum << "\n";
    }
}