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
        if(a[a.length() - 1] == '0') {
            long long ll = stoll(a);
            input.push_back(to_string(ll));
        }
        else {
            long long ll = stoll(a);
            input.push_back(to_string(ll));
        }
    }

    sort(input.begin(), input.end(), greater<>());
    sort(includeZero.begin(), includeZero.end(), greater<>());

    for(int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < includeZero.size(); i++) {
        cout << includeZero[i] << " ";
    }
    /*
    string answer = "";
    for(int i = 0; i < input.size(); i++) {
        answer += input[i];
    }

    for(int i = 0; i < includeZero.size(); i++) {
        answer += includeZero[i];
    }
    
    if(stoll(answer) == 0) {
        cout << 0;
    }
    else {
        cout << answer;
    }
    */
}