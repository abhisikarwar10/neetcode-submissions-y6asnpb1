class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,int> s;
         vector<int> out;

    for (int i = 0; i < nums.size(); i++){        
        int complement = target - nums[i];    
        if (s.find(complement) != s.end()){
            out.push_back(s[complement]);
            out.push_back(i);           
            return out;
        }
        s[nums[i]]=i;
    }
    }
};
