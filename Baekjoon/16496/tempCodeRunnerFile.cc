#include<bits/stdc++.h>

using namespace std;

int n;
vector<string> input;
vector<string> includeZero;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if(a[a.length() - 1] == '0') 
            includeZero.push_back(a);
        else 
            input.push_back(a);
    }

    sort(input.begin(), input.end(), greater<>());
    sort(includeZero.begin(), includeZero.end(), greater<>());

    string answer = "";
    for(int i = 0; i < input.size(); i++) {
        answer += input[i];
    }

    for(int i = 0; i < includeZero.size(); i++) {
        answer += includeZero[i];
    }

    cout << answer;
}