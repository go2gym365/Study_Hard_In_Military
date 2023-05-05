#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> isPrime(3001, true);

int combination(vector<int>& nums, int idx, int sum, int count)
{
    int res = 0;
    
    if(count == 3 && isPrime[sum] == true)
    {
        return 1;
    }
    else if(count == 3 && !isPrime[sum])
        return 0;
    
    for(int i = idx; i < nums.size(); i++)
    {
        res += combination(nums, i + 1, sum + nums[i], count + 1);
    }
    
    return res;
}

int solution(vector<int> nums) 
{
    int answer = 0;
    
    for(int i = 2 ; i < isPrime.size(); i++)
    {
        if(!isPrime[i])
            continue;
        for(int j = i+i; j < isPrime.size() - 1; j+=i)
        {
            if(isPrime[j])
                isPrime[j] = false;
        }
    }
    
    answer = combination(nums, 0, 0, 0);

    return answer;
}
