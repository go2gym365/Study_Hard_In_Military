#include<bits/stdc++.h>

using namespace std;

vector<int> player(101, 0);

int main() {
    int n;
    int levelSum = 0;
    int statSum = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> player[i];
    }

    sort(player.begin(), player.end(), greater<>());

    for(int i = 0; i < 42; i++) {
        levelSum += player[i];

        if(player[i] >= 250) statSum += 5;
        else if(player[i] >= 200 && player[i] < 250) statSum += 4;
        else if(player[i] >= 140 && player[i] < 200) statSum += 3;
        else if(player[i] >= 100 && player[i] < 140) statSum += 2;
        else if(player[i] >= 60 && player[i] < 100) statSum += 1;
    }

    cout << levelSum << " " << statSum;
}