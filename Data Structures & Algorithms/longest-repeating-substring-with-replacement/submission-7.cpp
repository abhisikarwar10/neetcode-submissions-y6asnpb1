class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> a;
        int l = 0;
        int maxx = 0;
        int res = 0;

        for(int r=0;r<s.size();r++){
            a[s[r]]++;
            maxx = max(maxx,a[s[r]]);
            if((r-l+1)-maxx>k){
                a[s[l]]--;
                l++;                
            }
            res = max(res,r-l+1);
        }
        return res;        
    }
};
