#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int arr[20];
        int n;
        int ans = 0;
        cin >> n;

        for(int i = 0; i < 20; i++) {
            cin >> arr[i];
        }

        for(int i = 0; i < 20; i++) {
            for(int j = i; j < 20; j++) {
                if(arr[i] > arr[j]) ans++;
            }    
        }
        cout << n << " " << ans << "\n";
    }
}