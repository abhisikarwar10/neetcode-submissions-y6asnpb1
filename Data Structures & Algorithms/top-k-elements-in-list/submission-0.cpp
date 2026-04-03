class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> n_f;
        vector<vector<int>> f_n(nums.size()+1);
        vector<int> out;
        int c = k;

        for (int i = 0; i < nums.size(); i++) {
            n_f[nums[i]]++;
        }
        for(auto i:n_f){
            f_n[i.second].push_back(i.first);
        }
        for(int i=nums.size();i>0;i--){
            for(auto j:f_n[i]){
                out.push_back(j);
                c--;
                if(c==0){
                    return out;
                }
            }            
            
        }
        return out;
    }
};
