#include<bits/stdc++.h>

using namespace std;

vector<int> block;

int main() {
    int n, m;
    cin >> n >> m;

    int maxValue = -98764231;
    int idx;

    for(int i = 0; i < m; i++) {
        int b; 
        cin >> b;

        if(maxValue < b) {
            maxValue = b;
            idx = i;
        }

        block.push_back(b);
    }

    int total = maxValue;

    int realBlockValue = maxValue;
    int highValue = 0;

    for(int i = 0; i < idx; i++) {
        if(highValue < block[i]) {
            highValue = block[i];

            total += block[i];
        }
        else if(highValue >= block[i]) {
            total += highValue;
        }
        
        realBlockValue += block[i];
    }

    highValue = 0;
    for(int i = m - 1; i > idx; i--) {
        if(highValue < block[i]) {
            highValue = block[i];
            total += block[i];
        }
        else if(highValue >= block[i]) {
            total += highValue;
        }
        realBlockValue += block[i];
    }

    cout << total - realBlockValue;
}