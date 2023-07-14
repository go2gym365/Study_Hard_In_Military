#include<bits/stdc++.h>

using namespace std;

int n, m;
int parent[1000001];

int find(int x) {
    if (parent[x] == x) //배열 인덱스와 값이 같으면 해당 값 리턴
        return x;
    
    return parent[x] = find(parent[x]); //배열의 값을 인덱스로 갖는 값 리턴
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);    //find연산을 통해 루트 노드를 가짐

    if(x == y) return;  //x와 y가 같다면 이미 연결되어 있는 것
    parent[y] = x;  //배열의 y인덱스에 x값을 저장
}

// 두 노드가 연결되어 있는지 판별하는 함수
void isUnion(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if(!o) 
            merge(a, b);
        else
            isUnion(a, b);
    }
}