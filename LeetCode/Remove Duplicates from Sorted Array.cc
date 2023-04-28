class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        set <int> S;

        for(int i = 0; i < nums.size(); i++)
        {
            S.insert(nums[i]);
        }

        int n = 0;

        for(auto a : S)
        {
            nums[n] = a;
            n++;
        }
        return n;
    }
};
