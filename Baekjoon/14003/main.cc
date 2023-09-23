#include<bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;

vector<int> input;
vector<int> lis;
int trace[1000001];

int binarySearch(int key) {
    int start = 0;
    int end = lis.size() - 1;

    int mid;
    while(start < end) {
        mid = (start + end) / 2;

        if(key > lis[mid]) {
            start = mid + 1;
        }
        else 
            end = mid;
    }
    return end;
}

void solve() {
    for(int i = 0; i < n; i++) {
        if(lis.empty() || lis.back() < input[i]) {
            trace[i] = cnt;
            lis.push_back(input[i]);
            cnt++;
        }
        else {
            int idx = binarySearch(input[i]);
            lis[idx] = input[i];
            trace[i] = idx;
        }
    }
    cout << cnt << "\n";
}

void print() {
    vector<int> tra;
    int tr = cnt - 1;
    for(int i = n-1; i >= 0; i--) {
        if(trace[i] == tr) {
            tra.push_back(input[i]);
            tr--;
        }
    }

    for(int i = tra.size() - 1; i >= 0; i--) {
        cout << tra[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        input.push_back(a);
    }

    solve();
    print();
}