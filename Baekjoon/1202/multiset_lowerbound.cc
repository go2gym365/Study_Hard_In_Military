#include<bits/stdc++.h>
#include <queue>
#include <set>

using namespace std;

priority_queue<pair<int, int>> pq;
multiset<int> bag;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    long long n, k;
    long long answer = 0;

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        pq.push({value, weight});
    }

    for(int i = 0; i < k; i++) {
        int size;
        cin >> size;
        bag.insert(size);
    }
    
    
    while(!bag.empty()){
        if(pq.empty()) break; //보석보다 가방이 많다면 (보석 다 담으면) 종료
        pair<int,int> tmp = pq.top(); pq.pop();
        //lower_bound를 활용하여 현재 보석의 무게와 같거나 더 큰 가방을 찾는다.
        multiset<int>::iterator iter = bag.lower_bound(tmp.second);
        if(iter==bag.end()) continue; //모든가방이 보석보다 작다면 못담음
        else bag.erase(iter); //보석 담은 가방은 제거
        answer+=tmp.first;
    }

    cout << answer;
}