#include<bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;

vector<int> lis;
vector<pair<int, int>> input;
int trace[100001];
map<int, int> m;

int binarySearch(int key) {
    int start = 0;
    int end = lis.size() - 1;
    int mid;

    while(start < end) {
        mid = (start + end) / 2;
        if(key > lis[mid]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }

    return end;
}

void solve() {
    for(int i = 0; i < n; i++) {
        if(lis.empty() || lis.back() < input[i].second) {
            trace[i] = cnt;
            lis.push_back(input[i].second);
            cnt++;
        }
        else {
            //lis의 인덱스임
            int idx = binarySearch(input[i].second);
            lis[idx] = input[i].second;
            trace[i] = idx;
        }
    }
}

void print() {
    cout << n - cnt << "\n";
    int tr = cnt - 1;
    vector<int> tra;
    for(int i = n - 1; i >= 0; i--) {
        if(trace[i] == tr) {
            tr--;
        }
        else {
            tra.push_back(input[i].first);
        }
    }
    for(int i = tra.size() - 1; i >= 0; i--) {
        cout << tra[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        m[b] = a;
        input.push_back({a, b});
    }

    sort(input.begin(), input.end());

    solve();
    print();
}