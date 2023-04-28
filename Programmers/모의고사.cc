#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<pair<int, int>> answer;
    vector<int> ans;
    vector<int> p1 { 1, 2, 3, 4, 5 };
    vector<int> p2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> p3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    
    int P1 = 0, P2 = 0, P3 = 0;
    
    for(int i = 0; i < answers.size() ; i++)
    {
        P1 += p1[i % p1.size()] == answers[i] ? 1 : 0;
        P2 += p2[i % p2.size()] == answers[i] ? 1 : 0;
        P3 += p3[i % p3.size()] == answers[i] ? 1 : 0;
    }
    
    answer.push_back({P1, 1});
    answer.push_back({P2, 2});
    answer.push_back({P3, 3});

    sort(answer.begin(), answer.end(), greater<>());
    
    int best = answer[0].first;
    ans.push_back(answer[0].second);
    
    for(auto a : answer)
    {
        if(best == a.first)
            ans.push_back(a.second);
        else
            break;
    }
    
    sort(ans.begin(), ans.end());
    
    return ans;
}
