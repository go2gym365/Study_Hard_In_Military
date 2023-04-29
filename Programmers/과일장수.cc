#include <bits/stdc++.h>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int count = 0;
    sort(score.begin(), score.end());
    
    reverse(score.begin(), score.end());
    
    for(int i = 0; i < score.size() ; i++)
    {
        count++;
        if(count == m)
        {
            answer += score[i] * m;
            count = 0;
        }
    }
    
    return answer;
}

