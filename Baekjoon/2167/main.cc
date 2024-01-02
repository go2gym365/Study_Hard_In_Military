#include<bits/stdc++.h>

using namespace std;

int n, m, k;

int arr[301][301];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
	    for(int j = 1; j <= m; j++) {
	        cin >> arr[i][j];
	    }
	}
	
	cin >> k;
	
	for(int i = 0; i < k; i++) {
	    int a, b, x, y;
	    cin >> a >> b >> x >> y;
	    
	    int sum = 0;
	    
	    for(int j = a; j <= x; j++) {
	        for(int l = b; l <= y; l++) {
	            sum += arr[j][l];
	        }
	    }
	    
	    cout << sum << '\n';
	}
}