#include <bits/stdc++.h>
using namespace std;

vector<int> sol;

int n;

void twoPointer() {
    int left = 0;
    int right = n - 1;
    int sum = INT_MAX;
    int a, b;

    while(left < right) {
        int temp = sol[left] + sol[right];
        if(abs(temp) < abs(sum)) {
            sum = temp;
            a = sol[left];
            b = sol[right];
        }

        if(temp == 0) break;
        else if(temp > 0) right--;
        else left++;
    }
    cout << a << " " << b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        sol.push_back(a);
    }

    twoPointer();
}