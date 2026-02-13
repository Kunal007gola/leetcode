class Solution {
public:
    int rob(vector<int>& nums) {
        
        int rob1 = 0, rob2 = 0;

        int temp = 0;
        // [rob1, rob2, i, i+1, .....]
        // uptil these 3 i can choose [rob1, rob2, i,]
        // either this (rob1 + i)
        // or this (rob2)
        // and shift them forward for i+1th computes
        for (int i: nums){
            temp = max(rob1 + i, rob2);

            rob1 = rob2;
            rob2 = temp;
        }

        return rob2;
    }
};