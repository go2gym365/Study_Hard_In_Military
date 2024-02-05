#include<bits/stdc++.h>

using namespace std;

int calc(string str1, string str2) {
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        if(str1[i] != str2[i]) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        string arr[100001];
        int n;
        cin >> n;
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        if(n > 32) {
            cout << "0" << '\n';
            continue;
        }
        
        int ans = 18;
        
        for(int i = 0; i < n-2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                for(int k = j + 1; k < n; k++) {
                    ans = min(ans, calc(arr[i], arr[j]) + calc(arr[j], arr[k]) + calc(arr[k], arr[i]));
                }
            }
        }
        cout << ans << '\n';
    }
}