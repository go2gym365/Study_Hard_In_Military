#include <bits/stdc++.h>

using namespace std;

int n, m;
bool swit[101];

void manSwitch(int num) {
    for(int i = num; i <= n; i += num) {
        swit[i] = !swit[i];
    }
}

void womanSwitch(int num) {
    swit[num] = !swit[num];
    int start = num-1;
    int end = num+1;
    while(swit[start] == swit[end]) {
        if(start == 0 || end == n+1) return;
        swit[start] = !swit[start];
        swit[end] = !swit[end];
        start--; end++;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> swit[i];
    }
    
    cin >> m;
    for(int i = 0; i < m; i++) {
        int gender, light;
        cin >> gender >> light;
        
        if(gender == 1) {
            manSwitch(light);
        }
        else if(gender == 2) {
            womanSwitch(light);
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << swit[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
}
