class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = 0;
        for (int i = s.length()-1 ; i >= 0 ; i--)
        {
            if(s[i] != ' ' )
                n++;
            else if(s[i] == ' ' && n > 0)
            {
                break;
            }
        }
        return n;
    }
};
