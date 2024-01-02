#include<bits/stdc++.h>

using namespace std;

int dp[501][501];
int psum[501];
int input[501];

int n;

int solve(int left, int right) {
    if(left == right) return 0;
    
    int &ret = dp[left][right];
    if(ret != -1) return ret;
    ret = 0x3f3f3f3f;
    
    for(int i = left; i < right; i++) {
        int temp = solve(left, i) + solve(i+1, right);
        //파일 각자의 용량만 더해줌
        temp += psum[i] - (left > 0 ? psum[left-1] : 0); //쪼개진 부분에서 왼쪽 구하기
        temp += psum[right] - psum[i]; //쪼개진 부분에서 오른쪽 구하기
        
        ret = min(ret, temp);
    }
    
    return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
	    memset(dp, -1, sizeof(dp));
	    memset(input, 0, sizeof(input));
	    
	    cin >> n;
	    
	    for(int i = 0; i < n; i++) {
	        cin >> input[i];
	        psum[i] = input[i];
	        if(i > 0) psum[i] += psum[i-1];
	    }
	    cout << solve(0, n-1) << '\n';
	}
}