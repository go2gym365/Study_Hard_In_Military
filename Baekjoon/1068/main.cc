#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, root, removeNode;
int leafCnt = 0;
vector<int> tree[51];
bool vis[51];

int solve(int node) {
    if(node == removeNode) return -1;
    if(!tree[node].size()) {
        leafCnt++;
        return 0;
    }
    
    for(int i = 0; i < tree[node].size(); i++) {
        int temp = solve(tree[node][i]);
        if (temp == -1 && tree[node].size() == 1)
            leafCnt++;
    }
    return 0;
}

int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        if(a == -1) root = i;
        else tree[a].push_back(i);
    }

    cin >> removeNode;
    
    solve(root);
    
    cout << leafCnt;
}
