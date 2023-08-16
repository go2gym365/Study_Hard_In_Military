#include<bits/stdc++.h>

using namespace std;

vector<int> positive;
vector<int> negative;

int main() {
    int n, m;
    
    cin >> n >> m;

    int ex = 0;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if(abs(ex) < abs(a)) {
            ex = a;
        }

        if(a > 0)
            positive.push_back(a);
        else if(a < 0)
            negative.push_back(a);
    }

    sort(negative.begin(), negative.end());
    sort(positive.begin(), positive.end(), greater<>());

    if(ex > 0) {
        int sum = ex;

        for(int i = m; i < positive.size(); i+=m) {
            sum += positive[i] * 2;
        }

        for(int i = 0; i < negative.size(); i+=m) {
            sum += abs(negative[i] * 2);
        }
        cout << sum;
    }
    else if(ex < 0) {
        int sum = abs(ex);
        for(int i = 0; i < positive.size(); i+=m) {
            sum += positive[i] * 2;
        }

        for(int i = m; i < negative.size(); i+=m) {
            sum += abs(negative[i] * 2);
        }

        cout << sum;
    }
}