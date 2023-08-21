#include<bits/stdc++.h>

using namespace std;

vector<int> vec;

const int INF = 0x3f3f3f3;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
    }
    
    int start = 0;
    int end = 0;
    int sum = vec[0];
    int length = INF;

    while(end < n) { // end가 끝까지 가봐야 n최대
        if(sum >= m) // length 갱신해주는 조건이 m이상이기 떄문에
            length = min(length, end - start + 1);

        if(sum < m) {
            end++;
            sum += vec[end];
        } 
        else if(sum == m) {
            cnt++;
            
            end++;
            sum += vec[end];
        }
        else if(sum >= m) {
            sum -= vec[start];
            start++;
        }
    }

    if(length == INF) {
        cout << '0';
    }
    else {
        cout << length;
    }
}