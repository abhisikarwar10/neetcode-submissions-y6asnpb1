class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int out = 0;
        int maxl = height[l];
        int maxr = height[r];

        while(r>l){
            if(maxl>maxr){
                r--;
                if(maxr-height[r]>0){
                    out+=(maxr-height[r]);
                }else{
                    maxr=height[r];
                }               
            }else{
                l++;
                if(maxl-height[l]>0){
                    out+=(maxl-height[l]);
                }else{
                    maxl=height[l];
                }  
            }
        }
        return out;
    }
};
