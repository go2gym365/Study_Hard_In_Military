#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> v;
    int n;
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        v.push_back(str[i] - '0');

    }

    sort(v.begin(), v.end(), greater<>());

    if (str[str.size() - 1] == '0' && stoi(str) % 3 == 0)
		cout << stoi(str);
	else cout << -1;
}