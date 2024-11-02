class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        bool isDuplicate[201] = {false, };
        vector<int> temp;
        int answer = 0;
        int idx = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            idx = nums[i] + 100;
            if(false == isDuplicate[idx])
            {
                isDuplicate[idx] = true;
                temp.push_back(nums[i]);
                answer++;
            }
        }
        sort(temp.begin(), temp.end());
        nums =  move(temp);
        return answer;
    }
};