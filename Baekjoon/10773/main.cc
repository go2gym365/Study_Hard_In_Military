#include<bits/stdc++.h>

using namespace std;

stack<int> s;

int main() {
    int t;
    long long sum = 0;

    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        if(n != 0) {
            s.push(n);
            sum += n;
        }
        else if(n == 0) {
            sum -= s.top();
            s.pop();
        }
    }
    cout << sum;
}