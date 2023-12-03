#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> um;

int node[200001];
int friendNum[200001];

int find(int x) {
    if(node[x] == x) return x;
    
    return node[x] = find(node[x]);
}

void merge(int n1, int n2) {
    int x = find(n1);
    int y = find(n2);
    
    if(x == y) return;
    
    if(x < y) {
        node[y] = x;
        friendNum[x] += friendNum[y];
    }
    else {
        node[x] = y;
        friendNum[y] += friendNum[x];
    }

}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    int t;
    cin >> t;
    
    while(t--) {
        um.clear();
        for(int i = 1; i <= 200001; i++) {
            node[i] = i;
            friendNum[i] = 1;
        }
        
        int n;
        cin >> n;
        
        int number = 1;
        for(int i = 0; i < n; i++) {
            string name1, name2;
            cin >> name1 >> name2;
            
            if(!um[name1]){
                um[name1] = number;
                number++;
            }
            if(!um[name2]){
                um[name2] = number;
                number++;
            }
            
            int a = um[name1];
            int b = um[name2];
            
            merge(a, b);
            int root = find(a);
            cout << friendNum[root] << '\n';
        }
    }
}
