class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> a;
        for(int i=0;i<s.size();i++){
            a[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            a[t[i]]--;
        }
        for(auto z:a){
            if(z.second != 0){
                return false;
            }
        }
        return true;
    }
};
