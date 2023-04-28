class Solution {
public:
    bool isPalindrome(int x) 
    {
        stack<int> stk;
        if(x < 0)
            return false;
        
        int y = x;
        while(x)
        {
            stk.push(x%10);
            x /= 10;
        }

        while(y)
        {
            if(stk.top() != (y%10))
                return false;
            stk.pop();
            y /= 10;
        }
        return true;
    }
};
