class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int m=(l+r)/2;

        while(l<=r){
            if(nums[m] == target){
                return m;
            }
            
            else if(nums[m]>nums[r]){
                if(target<nums[m] && target>=nums[l]){
                    r=m-1;
                }else{
                    l=m+1;
                }
                
            }else{
                if(target>nums[m] && target<=nums[r]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }           
            m=(l+r)/2;
        }
        return -1;   
    }
};
