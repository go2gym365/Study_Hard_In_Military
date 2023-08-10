#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        vector<int> vec;
        long long profit = 0;
        int maxValue = 0;
        int n;

        cin >> n;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            vec.push_back(a);
        }


        for(int i = n - 1; i >= 0; i--){
            if(vec[i] < maxValue) {
                profit += (maxValue - vec[i]);
            }
            else {
                maxValue = vec[i];
            }
        }
        cout << profit << "\n";
    }
}