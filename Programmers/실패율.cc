#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<double, int> a, pair<double, int> b)
{
    if(a.first == b.first) 
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    map<int, double> m;
    vector<pair<double, int>> pv;
    
    for(int i = 0; i < stages.size(); i++)
    {
        m[stages[i]]++;
    }
    
    double minus_member = 0;
    
    for(int i = 1; i <= N; i++)
    {
        if(m[i] == 0)
        {
            pv.push_back({0, i});
            continue;
        }
        else
        {
            pv.push_back({m[i] / (stages.size()-minus_member), i});
            minus_member += m[i];            
        }
    }
    sort(pv.begin(), pv.end(), cmp);
    
    for(auto a : pv)
    {
        answer.push_back(a.second);
    }
    return answer;
}
