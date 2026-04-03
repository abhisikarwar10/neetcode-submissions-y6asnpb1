class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int m = (l+r)/2;
        int res = 0;

        while(l<=r){
            int tt = 0;
            for(int i=0;i<piles.size();i++){
                tt+=ceil(static_cast<double>(piles[i])/m);
            }
            if(tt<=h){
                res = m;
                r = m-1;
            }else{
                l = m+1;
            }
            m = (l+r)/2;
        }
        return res;



    }
};
