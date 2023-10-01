#include<bits/stdc++.h>

using namespace std;

int node[9];

int find(int x) {
    if(node[x] == x)
        return x;
    
    return node[x] = find(node[x]);
}

void merge(int a, int b) {
    int x = find(a);
    int y = find(b);
    
    if(x == y) return;
    
    if(x != y) {
        //노드 값이 작은 쪽으로 붙도록 : 재귀 도는 시간 줄어듬
        if(x < y) node[y] = x;
        else node[x] = y;
    }
}

bool isUnion(int a, int b) {
    int x = find(a);
    int y = find(b);

    if(x == y) return true;
    else return false;
}

int main() {
	for (int i = 1; i <= 8; i++) // 배열 초기화 과정
		node[i] = i;

	merge(1, 2);
	merge(4, 5);
	merge(5, 6);
	cout << "2와 4는 같은 집합인가?\n" << isUnion(2, 4) << "\n"; // false
	merge(1, 5);
	cout << "2와 4는 같은 집합인가?\n" << isUnion(2, 4) << "\n"; // true
	return 0;
}