#include <iostream>
#include <map>

using namespace std;

map<long long, long long> m;

int main()
{
    long long ans = 0;
    
    long long n; cin >> n;
    
    while(n--) {
        long long a;
        cin >> a;
        
        m[a]++;
        ans = max(ans, m[a]);
    }
    
    for(auto &a : m) {
        if(a.second == ans) {
            cout << a.first;
            return 0;
        }
    }
}
