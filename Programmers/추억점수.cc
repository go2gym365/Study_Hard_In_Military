#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    vector<int> answer;
    int val = 0;
    map<string, int> vm;
    
    for(int i = 0 ; i < name.size() ; i++)
    {
        vm[name[i]]=yearning[i];
    }
    
    for(int i = 0 ; i < photo.size() ; i++)
    {
        for(int j = 0; j < photo[i].size() ; j++)
        {
            val += vm[photo[i][j]];
        }
        answer.push_back(val);
        val = 0;
    }
    
    return answer;
}