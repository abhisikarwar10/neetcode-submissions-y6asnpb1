class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l[nums.size()] = {};
        int r[nums.size()] = {};
        int pl = 1;int pr = 1;
        l[0]=1; r[nums.size()-1]=1;
        vector<int> out;

        for(int i=1;i<nums.size();i++){
            pl=pl*nums[i-1];
            l[i] = pl;
        }

        for(int i=nums.size()-2;i>=0;i--){
            pr=pr*nums[i+1];
            r[i] = pr;
        }

        for(int i=0;i<nums.size();i++){
            out.push_back(l[i]*r[i]);
        }
        return out;
    }
};
