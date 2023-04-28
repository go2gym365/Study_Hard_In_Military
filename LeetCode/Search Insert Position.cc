class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n = 0;
        for(int i = 0; i < nums.size() ; i++)
        {
            if(nums[i] == target)
                return i;
            else
            {
                nums.push_back(target);
                sort(nums.begin(), nums.end());
                n = find(nums.begin(), nums.end(), target) - nums.begin();
                break;
            }
        }
        return n;

    }
};
