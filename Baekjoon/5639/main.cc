#include<bits/stdc++.h>

using namespace std;

vector<int> tree;

void postOrder(int start, int end) {
    if(start >= end) return;
    if(start == end - 1) {
        cout << tree[start] << "\n";
        return;
    }

    int idx = start + 1;
    while(idx < end) {
        if(tree[start] < tree[idx]) break;
        idx++;
    }

    postOrder(start+1, idx);
    postOrder(idx, end);
    cout << tree[start] << "\n";
    return;
}

int main() {
    int num;
    while(cin >> num) {
        tree.push_back(num);
    }

    postOrder(0, tree.size());
}