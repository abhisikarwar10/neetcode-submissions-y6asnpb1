class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> um;
        int out = 0;
        int max = 0;

        for(int i=0;i<nums.size();i++){
            um[nums[i]]=0;
        }

        for(int i=0;i<nums.size();i++){
            um[nums[i]]=1;
            out = 1;
            int k = nums[i]-1;
            while(um.find(k)!=um.end() && um[k]!=1){
                um[k]=1;         
                out++;
                k--;
            }
            k = nums[i]+1;
            while(um.find(k)!=um.end() && um[k]!=1){
                um[k]=1;         
                out++;
                k++;
            }
            if(out>max){
                max = out;
            }
        }
        return max;

    }
};
