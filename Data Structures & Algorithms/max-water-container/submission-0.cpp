class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;
        int m =0;
        int h=0;

        while(i<j){
            h = min(heights[i],heights[j])*(j-i);
            if(h>m){
                m = h;
            }
            if(heights[i]>=heights[j]){
                j--;
            }else{
                i++;
            }
        }
        return m;
    }
};
