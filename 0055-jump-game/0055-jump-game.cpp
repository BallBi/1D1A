class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int goal = nums.size() - 1;

        for(int i=0; i < nums.size(); ++i)
        {
            if(i > maxIndex)
                return false;
            
            maxIndex = max(i + nums[i], maxIndex);

            if(maxIndex >= goal)
                return true;
        }

        return false;
    }
};