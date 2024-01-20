#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums;
    
    int check = 0;

    string str;
    cin >> str;

    for(int i = 0 ; i < str.size() ; ++i){
        nums.push_back(str[i]-'0');
    }

    sort(nums.rbegin() , nums.rend());

    for(int i = 0 ; i < nums.size(); i++){
        check += nums[i];
    }
    
    if(check % 3 != 0) cout << -1; 
    else if(nums[nums.size()-1] != 0) cout << -1;
    else{
        for(auto x : nums) cout << x;
    }
}