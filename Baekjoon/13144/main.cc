#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> input;
map<int, int> m; //수열에 등장하는 숫자가 중복인지 확인

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    int start = 0;
    int end = 0;
    long long ans = 0;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
    }    

    m[input[start]] = 1;

    while(true) {
        //input[end+1]이 선택한 수열에 없을경우 추가
        while(end < n - 1 && m[input[end + 1]] == 0) {
            end++;
            m[input[end]]++;
        }
        if(start >= n || end >= n) break;

        ans += end - start + 1;
        m[input[start]]--;
        start++;
    }

    cout << ans;
}