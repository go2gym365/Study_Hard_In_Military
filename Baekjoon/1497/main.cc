#include<bits/stdc++.h>

using namespace std;

long long songToBit[11];

int n, m;
int ans = 0x3f3f3f3f;
int maxCnt = 0;

int countBit(long long bit) {
    int cnt = 0;
    while(bit) {
        cnt += bit & 1;
        bit >>= 1;
    }
    return cnt;
}

void solve(int idx, long long bit, int cnt) {
    int bitToSong = countBit(bit);
    
    if(bitToSong > maxCnt) {
        maxCnt = bitToSong;
        ans = cnt;
    }
    else if(bitToSong == maxCnt) {
        ans = min(ans, cnt);
    }
    
    if(idx == n) return;
    
    solve(idx+1, bit | songToBit[idx], cnt+1);
    
    solve(idx + 1, bit, cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        string name, detail;
        cin >> name >> detail;
        
        for(int j = 0; j < m; j++) {
            if(detail[j] == 'Y') {
                songToBit[i] |= (1LL << (m-1-j));
            }
        }
    }
    
    solve(0, 0, 0);
    
    if(!maxCnt) cout << -1;
    else cout << ans;
}
