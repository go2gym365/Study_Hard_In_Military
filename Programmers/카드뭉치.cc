#include <string>
#include <vector>
#include <queue>

using namespace std;

queue<string> c1;
queue<string> c2;
queue<string> g;


void convert(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    for(int i = 0 ; i < cards1.size() ; i++)
        c1.push(cards1[i]);
    for(int i = 0 ; i < cards2.size() ; i++)
        c2.push(cards2[i]);
    for(int i = 0 ; i < goal.size() ; i++)
        g.push(goal[i]);
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "";
    bool res = true;

    convert(cards1, cards2, goal);
    
    while(!g.empty())
    {
        if(!c1.empty() && g.front() == c1.front())
        {
            g.pop();
            c1.pop();
        }
        else if(!c2.empty() && g.front() == c2.front())
        {
            g.pop();
            c2.pop();
        }
        else
        {
            res = false;
            break;
        }
    }
    
    if(res == true)
        answer += "Yes";
    else
        answer += "No";
    
    return answer;
}
