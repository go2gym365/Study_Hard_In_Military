#include<bits/stdc++.h>

using namespace std;

int n, m;

int num[100001];

void binarySearch(int target) {
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(num[mid] == target) {
            cout << '1' << "\n";
            return;
        }
        else if(num[mid] < target) {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << '0' << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        num[i] = a;
    }

    sort(num, num+n);

    cin >> m;
    for(int i = 0; i < m; i++) {
        int b;
        cin >> b;
        binarySearch(b);
    }
}