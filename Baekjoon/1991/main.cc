#include<bits/stdc++.h>

using namespace std;

int n;

pair<char, char> vec[26];

void preorder(char cur) {
    if(cur == '.') 
        return;

    cout << cur;
    preorder(vec[cur - 'A'].first);
    preorder(vec[cur - 'A'].second);
}

void inorder(char cur) {
    if(cur == '.') 
        return;

    inorder(vec[cur - 'A'].first);
    cout << cur;
    inorder(vec[cur - 'A'].second);
}

void postorder(char cur) {
    if(cur == '.') 
        return;

    postorder(vec[cur - 'A'].first);
    postorder(vec[cur - 'A'].second);
    cout << cur;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        
        vec[a - 'A'].first = b;
        vec[a - 'A'].second = c;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}