#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        if(arr.empty() || arr.back() < input) {
            arr.push_back(input);
        }
        else {
            *lower_bound(arr.begin(), arr.end(), input) = input;
        }
    }
    cout << arr.size();
}