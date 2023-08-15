#include<bits/stdc++.h>

using namespace std;

int n;
int zeroCnt = 0;

vector<int> positiveNum;
vector<int> negativeNum;

int main() {
    int ans = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int a; 
        cin >> a;

        if(a > 1)
            positiveNum.push_back(a);
        else if(a == 1)
            ans += 1;
        else if(a == 0)
            zeroCnt++;
        else if(a < 0) 
            negativeNum.push_back(a);
    }

    sort(positiveNum.begin(), positiveNum.end(), greater<>());
    sort(negativeNum.begin(), negativeNum.end());

    for(int i = 0; i < positiveNum.size(); i++) {
        if(positiveNum.size() - i == 1) {
            ans += positiveNum[i];
            continue;
        }
        ans += positiveNum[i] * positiveNum[i + 1];
        i++;
    }
    for(int i = 0; i < negativeNum.size(); i++) {
        if(negativeNum.size() - i == 1) {
            if(zeroCnt > 0) {
                zeroCnt--;
                continue;
            }
            ans += negativeNum[i];
            continue;
        }
        ans += negativeNum[i] * negativeNum[i + 1];
        i++;
    }

    cout << ans;
}