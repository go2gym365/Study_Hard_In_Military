#include<bits/stdc++.h>

using namespace std;

vector<int> vec;    // 정렬 후 중복제거
vector<int> vec2;

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        vec.push_back(a);
        vec2.push_back(a);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    for(int i = 0; i < n; i++) {
        cout << lower_bound(vec.begin(), vec.end(), vec2[i]) - vec.begin() << " ";
    }
}