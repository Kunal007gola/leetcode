class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        

        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        int ans = min_coins(amount, coins, dp);
        // for (int i=0; i<dp.size(); i++){
        //     cout<<i<<" - "<<dp[i]<<endl;
        // }
        if (ans == INT_MAX){
            ans = -1;
        }
        return ans;
    }

    int min_coins(int n, vector<int>& a, vector<int>& dp){

        if (n==0){
            return 0;
        }

        int ans = INT_MAX;

        for (int i=0; i<a.size(); i++){

            if (n-a[i] >= 0){

                int sub_ans = 0;

                if (dp[n-a[i]] != -1){
                    sub_ans = dp[n-a[i]];
                } else{
                    sub_ans = min_coins(n-a[i], a, dp);
                }

                if (sub_ans != INT_MAX && sub_ans + 1 < ans){
                    ans = sub_ans + 1;
                }

            }
        }
        dp[n] = ans;
        return ans;
    }
};