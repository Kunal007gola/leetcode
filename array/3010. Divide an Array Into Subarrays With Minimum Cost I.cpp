class Solution {
public:
    int minimumCost(vector<int>& nums) {

        int min_ans = nums[0];
        sort(nums.begin() + 1, nums.end());

        min_ans += nums[1] + nums[2];       
        return min_ans;
    }
};