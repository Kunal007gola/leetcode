class Solution {
public:
    int maxVowels(string s, int k) {

        int l=0, cnt=0, res=0;
        string vowels = "aeiou";

        for (int r=0; r<s.size(); r++){

            
            if (r - l + 1 > k){
                if (vowels.contains(s[l])){
                    cnt--;
                }
                l++;
            }

            if (vowels.contains(s[r])){
                cnt++;
            }
            
            // cout<<l<<" "<<r<<" "<<s[r]<<" = "<<cnt<<endl;
            res = max(res, cnt);
        }
        
        return res;
    }
};