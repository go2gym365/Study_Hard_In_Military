#include <bits/stdc++.h>

using namespace std;

int solution(string s) 
{
    int answer = 0;
    string temp = "";
    string res = "";
    
    map<string, int> mp = {{"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
                           {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
    
    for(int i = 0 ; i < s.size(); i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            res += s[i];
        else
        {
            temp += s[i];
            
            if(mp.find(temp) != mp.end())
            {
                res += to_string(mp[temp]);
                temp = "";
            }
        }
    }
    answer = stoi(res);
    
    return answer;
}
