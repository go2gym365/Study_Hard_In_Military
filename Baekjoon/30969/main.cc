#include <bits/stdc++.h>

using namespace std;

int n;
int jinjuCost;
int highCostThenJinju;

int cost[1005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string str;
        long long c;
        
        cin >> str >> c;
        
        if(str == "jinju") {
            jinjuCost = c;
            continue;
        }
        
        if(c > 1000) highCostThenJinju++;
        else cost[c]++;
    }
    
    for(int i = jinjuCost+1; i < 1001; i++) {
        highCostThenJinju += cost[i];
    }
    
    cout << jinjuCost;
    cout << '\n' << highCostThenJinju;
    
}