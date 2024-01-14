#include<bits/stdc++.h>

using namespace std;

int n, k;

vector<pair<int, int>> input;
queue<int> q;
int trace[51];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) {
	    int priority;
	    cin >> priority;
	    
	    input.push_back({priority, i});
	}
	
	sort(input.begin(), input.end(), greater<pair<int, int>>());
	
	for(int i = 0; i < k; i++) {
	    trace[input[i].second] = input[i].second;
	    
	    q.push(input[i].second);
	}
	
	while(!q.empty()) {
	    cout << q.front() << '\n';
	    q.pop();
	}
	
	for(int i = 1; i <= n; i++) {
	    cout << trace[i] << '\n';
	}
}