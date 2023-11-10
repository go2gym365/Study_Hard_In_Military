#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int t, w;

int dp[1001][31][3];

vector<int> tree;

int solve(int cnt, int moveCnt, int treeNum) {
    if(cnt == t+1) return 0;
    
    int &ret = dp[cnt][moveCnt][treeNum];
    if(ret != -1) return ret;
    
    ret = 0;
    
    if(cnt == 0) {
        //원래 1의 자리에서 시작
        ret = max(ret, solve(cnt+1, moveCnt, 1));
        // 2의 자리로 옮겨서 시작
        ret = max(ret, solve(cnt+1, moveCnt+1, 2));
    }
    else {
        if(tree[cnt] == treeNum) {
            ret = max(ret, solve(cnt+1, moveCnt, treeNum) + 1);
            if(treeNum == 1 && moveCnt+1 <= w) {
                ret = max(ret, solve(cnt+1, moveCnt+1, 2)+1);
            }
            else if(treeNum == 2 && moveCnt+1 <= w){
                ret = max(ret, solve(cnt+1, moveCnt+1, 1)+1);
            }
        }
        else {
            if(treeNum == 1) {
                ret = max(ret, solve(cnt+1, moveCnt, 1));
            }
            else {
                ret = max(ret, solve(cnt+1, moveCnt, 2));
            }
        }
        
        if(treeNum == 1 && moveCnt+1 <= w) {
            ret = max(ret, solve(cnt+1, moveCnt+1, 2));
        }
        else if(treeNum == 2 && moveCnt+1 <= w){
            ret = max(ret, solve(cnt+1, moveCnt+1, 1));
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    
    cin >> t >> w;
    
    tree.push_back(-1);
    
    for(int i = 0; i < t; i++) {
        int tr;
        cin >> tr;
        
        tree.push_back(tr);
    }
    
    cout << solve(0, 0, 1);
}
