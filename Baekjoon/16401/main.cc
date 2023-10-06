#include<bits/stdc++.h>

using namespace std;

int nephew, cookie;

vector<int> input;

bool check(int val) {
    int ret = 0;

    if(nephew < cookie) {
        for(int i = cookie - nephew - 1; i < cookie; i++) {
            ret += input[i] / val;
        }
    }
    else {
        for(int i = 0; i < cookie; i++) {
            ret += input[i] / val;
        }
    }
    
    if(ret >= nephew) {
        return true;
    }
    else return false;
}

int binarySearch() {
    int maxLength = 0;
    int left = 1;
    int right = input[cookie - 1];
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;

        if(check(mid)) {
            maxLength = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return maxLength;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> nephew >> cookie;

    for(int i = 0; i < cookie; i++) {
        int a;
        cin >> a;

        input.push_back(a);
    }

    sort(input.begin(), input.end());

    cout << binarySearch();
}