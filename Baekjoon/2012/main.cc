#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        vec.push_back(a);
    }
    
    sort(vec.begin(), vec.end());
    
    long long ans = 0;
    
    for(int i = 1; i <= n; i++) {
        ans += abs(vec[i-1] - i);
    }
    
    cout << ans;

    return 0;
}
