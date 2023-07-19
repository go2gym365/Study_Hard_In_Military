#include<bits/stdc++.h>

using namespace std;

int arr[21] = {0, };

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    string str;
    cin >> m;

    for(int i = 0; i < m; i++) {
        string str;
        int a;
        cin >> str;

        if(str == "add") {
            int a;
            cin >> a;
            
            arr[a] = 1;
        }
        else if(str == "remove") {
            cin >> a;
            arr[a] = 0;
        }
        else if(str == "check") {
            cin >> a;
            if(arr[a]) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(str == "toggle") {
            cin >> a;
            if(arr[a]) arr[a] = 0;
            else arr[a] = 1;
        }
        else if(str == "all") {
            for(int i = 1; i <= 20; i++) {
                arr[i] = i;
            }
        }
        else if(str == "empty") {
            for(int i = 0; i < 21; i++) {
                arr[i] = 0;
            }
        }
    }
}