#include<bits/stdc++.h>

using namespace std;

int parent[10];

int find(int x) {
    if(parent[x] == x);
        return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    parent[y] = x;
}

bool isUnion(int x, int y) {
    int x = find(x);
    int y = find(y);

    if(x == y)
        return true;
    return false;
}

int main() {
     for(int i = 1; i < 10; i++) 
        parent[i] = i;
    
    merge(1, 2);
	merge(4, 5);
	merge(5, 6);
	cout << "2와 4는 같은 집합인가?\n" << isUnion(2, 4) << "\n"; // false
	merge(1, 5);
	cout << "2와 4는 같은 집합인가?\n" << isUnion(2, 4) << "\n"; // true
	return 0;
}