class Solution {
public:

    // bottom-up
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector(m+1, 0));

        for (int i=1; i<n+1; i++){

            for (int j=1; j < m+1; j++){

                if (text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(
                        dp[i-1][j], dp[i][j-1]
                    );
                }
            }
        }
        return dp[n][m];
    }

    // top-down
    // int longestCommonSubsequence(string text1, string text2) {

    //     int n = text1.size() - 1;
    //     int m = text2.size() - 1;

    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1,-1));

    //     return lcs_util(n,m,text1, text2, dp);
        
    // }

    // int lcs_util(int n, int m, string s1, string s2, vector<vector<int>> dp){

    //     if (n== -1 || m == -1){
    //         return 0;
    //     }

    //     if (dp[n][m] != -1){
    //         return dp[n][m];
    //     }

    //     if (s1[n] == s2[m]){
    //         return dp[n][m] = 1 + lcs_util(n-1, m-1, s1, s2, dp);
    //     }

    //     else {
    //         return dp[n][m] = max(
    //             lcs_util(n-1, m, s1, s2, dp),
    //             lcs_util(n, m-1, s1,s2, dp)
    //         );
    //     }
    // }
};