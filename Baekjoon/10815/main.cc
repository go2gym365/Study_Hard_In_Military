#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> card;
vector<int> input;

void binarySearch(int target) {
    int start = 0;
    int end = n - 1;
    int mid;

    while(start <= end) {
        mid = (start + end) / 2;

        if(card[mid] == target) {
            cout << 1 << " ";
            return;
        }

        if(card[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    cout << 0 << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        card.push_back(a);
    }

    sort(card.begin(), card.end());

    cin >> m;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        binarySearch(a);
    }
}