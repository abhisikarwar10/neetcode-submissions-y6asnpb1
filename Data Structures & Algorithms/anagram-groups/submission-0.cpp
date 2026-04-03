class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        vector<vector<string>> out;
        for(int i=0;i<strs.size();i++){
            string key = "";
            vector<int> count(26,0);
            string curr = strs[i];
            for(int j=0;j<curr.size();j++){
                count[curr[j]-'a']++;
            }
            for(auto a:count){
                key+=to_string(a) + ',';
            }
            um[key].push_back(curr);
        }
        for(auto x:um){
            vector<string> z;
            for(auto y:x.second){
                z.push_back(y);
            }
            out.push_back(z);
        }
        return out;
    }
};
