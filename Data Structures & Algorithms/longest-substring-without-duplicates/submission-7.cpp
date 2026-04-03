class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lo;
        int maxx = 0;
        int last = 0;
        for(int i = 0;i<s.size();i++){
            if(lo.find(s[i])!=lo.end()){
                last = max(last,lo[s[i]]+1);                
            }
                if(i-last+1>maxx){
                  maxx = i-last+1;
                }
            lo[s[i]]=i;
        }
        return maxx;
    }
};
