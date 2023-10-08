#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> input;
vector<int> sum;
map<int, bool> m;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        input.push_back(a);
        m[a] = true;
    }

    sort(input.begin(), input.end());

    for(int i = 0; i < n; i++) {
        int fix = input[i];
        int start = i+1;
        int end = n - 2;
        while(start < end) {
            if(fix + input[start] + input[end] ) {

            }
            else {

            }
        }
    }
}