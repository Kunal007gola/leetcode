class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& A) {
        // add your logic here
        // -4 -1 -1 0 1 2
        int s = A.size();
        int l, r, sum;
        vector<vector<int>> ans;

        if (s < 3) {
            return ans;
        }

        sort(A.begin(), A.end());

        for (int i = 0; i < s - 1; i++) {

            l = i + 1;
            r = s - 1;

            if(i > 0 && A[i] == A[i - 1]) {
                continue;
            }

            while (l < r) {

                if(r < (s - 1) && A[r] == A[r + 1]) {
                    r--;
                    continue;
                }
                sum = A[i] + A[l] + A[r];
                // cout<<i<<","<<A[i]<<" "<<l<<","<<A[l]<<" "<<r<<","<<A[r]<<"\n";

                if (sum == 0) {
                    vector<int> a{A[i], A[l], A[r]};
                    ans.push_back(a);
                    l++;
                    r--;
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};